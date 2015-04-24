#include <stack>
#include <stdexcept>

using std::stack;
using std::length_error;

// QueueTwoStacks implements a simple queue on top of two underlying stacks.
template <class T, class Stack = stack<T> >
class QueueTwoStacks
{
public:
  bool empty() const { return A_.empty() && B_.empty(); }
  size_t size() const { return A_.size() + B_.size();  }
  const T& front() const {
    if (this->empty()) throw length_error("empty queue");
    this->shuffle();
    return B_.top();
  }
  T& front() {
    return const_cast<T&>(static_cast<const QueueTwoStacks&>(*this).front());
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
  Stack A_, B_;

  void shuffle();
};

template <class T, class Stack>
void QueueTwoStacks<T, Stack>::shuffle()
{
  if (B_.empty()) {
    while (!A_.empty()) {
      B_.push(A_.top());
      A_.pop();
    }
  }
}
