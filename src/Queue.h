// Queue implements a simple queue on top of an underlying container.
template <class T, class Container = CircularVector<T> >
class Queue
{
public:
  Queue() : cntr_(Container()) {}
  Queue(const Container& cntr) : cntr_(cntr) {}
  bool empty() const { return cntr_.empty(); }
  size_t size() const { return cntr_.size(); }
  const T& front() const {
    return cntr_.front();
  }
  T& front() {
    return const_cast<T&>(static_cast<const Queue&>(*this).front());
  }
  const T& back() const {
    return cntr_.back();
  }
  T back() {
    return const_cast<T&>(static_cast<const Queue&>(*this).back());
  }
  void push(const T& e) {
    cntr_.push_back(e);
  }
  void pop() {
    cntr_.pop_front();
  }
  void print() {
    cntr_.print();
  }

private:
  Container cntr_;

};
