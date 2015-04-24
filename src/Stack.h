// Stack implements a simple stack on top of an underlying container.
template <class T, class Container = vector<T> >
class Stack
{
public:
  typedef T value_type;

  Stack() : cntr_(Container()) {}
  Stack(const Container& cntr) : cntr_(cntr) {}
  bool empty() const { return cntr_.empty(); }
  size_t size() const { return cntr_.size(); }
  const T& top() const {
    return cntr_.back();
  }
  T& top() {
    return const_cast<T&>(static_cast<const Stack&>(*this).top());
  }
  void push(const T& e) {
    cntr_.push_back(e);
  }
  void pop() {
    cntr_.pop_back();
  }
  void print() {
    cntr_.print();
  }

private:
  Container cntr_;

};
