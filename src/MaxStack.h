#ifndef MAXSTACK
#define MAXSTACK

#include <stack>

using std::stack;
using std::length_error;

// MaxStack_1 implements a simple stack API with a maximum function on top of an underlying stack.
template <class T, class Stack = stack<pair<T, T> > >
class MaxStack_1
{
public:
  typedef T value_type;

  bool empty() const { return s_.empty(); };

  const T& top() const {
    if (this->empty()) throw length_error("stack empty");
    return s_.top().first;
  }
  const T& max() const {
    if (this->empty()) throw length_error("stack empty");
    return s_.top().second;
  }
  void push(const T& x) {
    s_.emplace(x, std::max(x, this->empty() ? x : s_.top().second ) );
  }
  void pop() {
    if (this->empty()) throw length_error("stack empty");
    s_.pop();
  }

private:
  Stack s_;

};

// MaxStack_2 implements a more space efficient stack API with a maximum function on top of an underlying stack.
template <class T, class Stack = stack<T>, class AuxStack = stack<pair<T, size_t> > >
class MaxStack_2
{
public:
  typedef T value_type;

  bool empty() const {
    return aux_.empty();
  }
  const T& max() const {
    if (this->empty()) { throw length_error("stack empty"); }
    return aux_.top().first;
  }
  const T& top() const {
    if (this->empty()) { throw length_error("stack empty"); }
    return s_.top();
  }

  void push(const T& x);
  void pop();

private:
  Stack s_;
  AuxStack aux_;

};

template <class T, class Stack, class AuxStack>
void MaxStack_2<T, Stack, AuxStack>::push(const T& x)
{
  s_.push(x);
  if (!this->empty()) {
    if (x == aux_.top().first) {
      (aux_.top().second)++;
    } else if (x > aux_.top().first) {
      aux_.emplace(x, 1);
    }
  } else {
    aux_.emplace(x, 1);
  }
}

template <class T, class Stack, class AuxStack>
void MaxStack_2<T, Stack, AuxStack>::pop()
{
  if (this->empty()) { throw length_error("stack empty"); }
  T top = s_.top();
  s_.pop();
  if (top == aux_.top().first) {
    --aux_.top().second;
    if (aux_.top().second == 0)
      aux_.pop();
  }
}

#endif
