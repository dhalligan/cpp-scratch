#include <queue>
#include <stdexcept>

using std::stack;
using std::length_error;

// StackOneQueue implements a simple stack on top of one underlying stack.
template <class T, class Queue = queue<T> >
class StackOneQueue
{
public:
  bool empty() const { return A_.empty(); }
  size_t size() const { return A_.size();  }
  const T& top() const {
    if (this->empty()) throw length_error("empty queue");
    return A_.front();
  }
  T& top() {
    return const_cast<T&>(static_cast<const StackOneQueue&>(*this).top());
  }
  void push(const T& e) {
    A_.push(e);
    for (int i = 0; i < A_.size() - 1; ++i) { A_.push(A_.front()), A_.pop(); }
  }
  void pop() {
    A_.pop();
  }

private:
  Queue A_;

};
