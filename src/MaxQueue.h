#include <stack>
#include <stdexcept>
#include "MaxStack.h"

using std::stack;
using std::length_error;

// MaxQueue implements a queue API with a maximum function on top of two underlying stacks with maximum functions.
template <class T, class MaxStack = MaxStack_2<T> >
class MaxQueue
{
public:
  bool empty() const { return A_.empty() && B_.empty(); }
  size_t size() const { return A_.size() + B_.size();  }
  const T& front() const {
    if (this->empty()) throw length_error("empty queue");
    this->shuffle();
    return B_.top();
  }
  const T& max() const {
    if (this->empty()) { throw length_error("empty queue"); }
    if (A_.empty()) { return B_.max(); }
    if (B_.empty()) { return A_.max(); }
    return std::max( A_.max(), B_.max() );
  }
  void push(const T& e) {
    A_.push(e);
  }
  void pop() {
    if (this->empty()) throw length_error("empty queue");
    this->shuffle();
    B_.pop();
  }

private:
  MaxStack A_, B_;

  void shuffle();
};

template <class T, class MaxStack>
void MaxQueue<T, MaxStack>::shuffle()
{
  if (B_.empty()) {
    while (!A_.empty()) {
      B_.push(A_.top());
      A_.pop();
    }
  }
}
