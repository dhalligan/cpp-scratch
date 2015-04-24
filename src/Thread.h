#include <thread>
#include <iostream>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <queue>

using std::thread;
using std::cout;
using std::endl;
using std::vector;
using std::mutex;
using std::unique_lock;
using std::condition_variable;
using std::queue;

void taskf(vector<double>& v, double* res);

struct TaskF {
  TaskF(vector<double>& vv, double* r) : v(vv), res(r) {}
  void operator() () {
    { cout << "Parallel world!" << endl; *res = 24; }    
  }
  vector<double>& v;
  double* res;
};

void user();


