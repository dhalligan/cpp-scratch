using std::vector;

// CircularVector implements a simple circular buffer on top of a dynamically resizing vector.
template <class T>
class CircularVector
{
  static const size_t default_capacity = 16;

public:
  typedef T value_type;

  CircularVector(size_t capacity = default_capacity) : data_(capacity) {}
  bool empty() const { return count_ == 0; }
  size_t size() const { return count_; }
  const T& front() const {
    if (!count_) throw std::length_error("empty vector");
    return data_[head_];
  }
  T& front() {
    return const_cast<T&>(static_cast<const CircularVector&>(*this).front());
  }
  const T& back() const {
    if (!count_) throw std::length_error("empty vector");
    return data_[(tail_ - 1) % data_.size()];
  }
  T& back() {
    return const_cast<T&>(static_cast<const CircularVector>(*this).back());
  }
  void push_back(const T& e);
  void pop_front();
  void print();

private:
  size_t head_ = 0, tail_ = 0, count_ = 0;
  vector<T> data_;
  double resize_factor = 2.0;
};

template <class T>
void CircularVector<T>::push_back(const T& e)
{
  if (count_ == data_.size()) {
    rotate(data_.begin(), data_.begin() + head_, data_.end());
    head_ = 0, tail_ = count_;
    data_.resize(resize_factor * data_.size());
  }
  data_[tail_] = e;
  count_++;
  tail_ = (tail_ + 1) % data_.size();
}

template <class T>
void CircularVector<T>::pop_front()
{
  if (!count_) throw std::length_error("empty vector");
  count_--;
  head_ = (head_ + 1) % data_.size();
}

template <class T>
void CircularVector<T>::print()
{
  for (size_t i = head_; i != tail_; i = (i + 1) % data_.size()) {
    cout << data_[i] << " ";
  }
  cout << endl;
}
