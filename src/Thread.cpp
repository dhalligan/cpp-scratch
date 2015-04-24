#include "Thread.h"

mutex m;
int sh;

struct Message {
  Message(int i) : t(i) {
    //    cout << "produced " << t << endl;
  }
  void process() {
    cout << "processed " << t << endl;
  }
  int t;
};

queue<Message> mqueue;
condition_variable mcond;
mutex mmutex;
void producer();
void consumer();

void taskf(vector<double>& v, double* res) { 
  *res = 42;
  cout << "hello" << endl; 
  unique_lock<mutex> lck {m};
  sh += 7;
  
}

void user()
{
  vector<double> some_vec {1, 2, 3, 4, 5, 6, 7, 8, 9};
  vector<double> vec2 {10, 11, 12, 13, 14};

  double res1 = 0, res2 = 0;
  thread t1 {taskf, ref(some_vec), &res1};
  thread t2 {TaskF(vec2, &res2)};

  t1.join();
  t2.join();

  cout << "res1 = " << res1 << ", res2 = " << res2 << endl;
  cout << sh << endl;

  thread p {producer};
  thread c {consumer};

  p.join();
  c.join();

}

void consumer()
{
  while (true) {
    unique_lock<mutex> lck{mmutex};
    mcond.wait(lck);
    
    auto m = mqueue.front();
    mqueue.pop();
    lck.unlock();
    
    // Process m. Don't need to be holding lock on mutex here.
    m.process();
  }
}

void producer()
{
  int i = 0;
  while (true) {
    Message m(i++);
    unique_lock<mutex> lck{mmutex};
    
    mqueue.push(m);
    mcond.notify_one();
  } // Implicitly release lock.
}
