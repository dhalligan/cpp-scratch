#include <stack>

using std::stack;
using std::shared_ptr;
using std::length_error;

// StackSet implements a stack interface on top of an underlying vector of stacks.
template <class T, class Stack = stack<T> >
class StackSet
{
  static const size_t default_capacity = 16;

public:
  typedef T value_type;

  StackSet(size_t capacity = default_capacity) : capacity_(capacity) {}
  bool empty() const { return stacks.empty(); }
  size_t size() const { return size_; }
  const T& top() const {
    if (stacks.empty()) { throw length_error("empty stack"); }
    return stacks.back()->top();
  }
  T& top() {
    return const_cast<T&>(static_cast<const StackSet&>(*this).top());
  }
  void push(const T& x);
  void pop();

private:
  vector<shared_ptr<Stack> > stacks;
  size_t size_ = 0;
  size_t capacity_;
};

template <class T, class Stack>
void StackSet<T, Stack>::pop()
{
  if (stacks.empty()) { throw length_error("empty stack"); }
  stacks.back()->pop();
  if (stacks.back->empty()) {
    stacks.pop();
  }
}

template <class T, class Stack>
void StackSet<T, Stack>::push(const T& x)
{
  if (stacks.empty() || stacks.back()->size() == capacity_) {
    stacks.emplace_back(make_shared<Stack>());
  }
  stacks.back()->push(x);
}
