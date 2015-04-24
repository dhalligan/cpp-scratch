#include <vector>
#include <queue>

using std::vector;
using std::priority_queue;

template <class T>
struct Heap_Compare {
  bool operator() (const pair<size_t,T>& lhs, const pair<size_t,T>& rhs) const {
    return lhs.second < rhs.second;
  }
};

template <class T>
class Heap
{
public:
  Heap(const size_t capacity) : count_(0), data_(capacity) {}
  Heap(const vector<T>& items) : count_(items.size()), data_(items) {
    this->heapify();
  }
  bool empty() const { return count_ == 0; }
  size_t size() const { return count_; }
  void push(const T& e) {
    if (count_ == data_.size()) {
      data_.resize(data_.size() << 1);
    }
    data_[count_] = e;
    this->bubble_up(count_++);
  }
  void pop() {
    if (count_ == 0) { throw std::length_error("empty heap"); }
    std::swap(data_[0], data_[count_ - 1]);
    count_--;
    this->bubble_down(0);
  }
  const T& top() const {
    if (count_ == 0) { throw std::length_error("empty heap"); }
    return data_[0];
  }
  T& top() {
    return const_cast<T&>(static_cast<const Heap&>(*this));
  }
  vector<T> k_largest(const size_t k) {
    return k_largest_impl(k);
  }
  bool check() const {
    return check_recursive_impl(0);
  }
  void print() const {
    for (auto e : data_) { std::cout << e << " "; }
    std::cout << std::endl;
  }

private:
  size_t count_;
  vector<T> data_;

  void bubble_up(const size_t idx);
  void bubble_down(const size_t idx);
  void heapify();
  bool check_impl() const;
  bool check_recursive_impl(const size_t idx) const;
  vector<T> k_largest_impl(const size_t k) const;

};

template <class T>
void Heap<T>::bubble_up(const size_t idx) {
  for (size_t j = idx; j != 0 && data_[(j - 1) / 2] < data_[j]; j = (j - 1) / 2) {
    std::swap(data_[(j - 1) / 2], data_[j]);
  }
}

template <class T>
void Heap<T>::bubble_down(const size_t idx) {
  for (size_t j = idx; 2 * j + 1 < count_; ) {
    size_t larger = 2 * j + 2 < count_ && data_[2 * j + 2] > data_[2 * j + 1] ? 2 * j + 2 : 2 * j + 1;
    if (data_[larger] > data_[j]) {
      std::swap(data_[larger], data_[j]);
      j = larger;
    } else {
      j = count_;
    }
  }
}

template <class T>
void Heap<T>::heapify()
{
  for (size_t j = count_ - 1; j >= 1;  --j) {
    this->bubble_down(j);
  }
  this->bubble_down(0);
}

template <class T>
bool Heap<T>::check_impl() const
{
  for (int j = 0; j < count_; ++j) {
    if (2 * j + 1 < count_) {
      size_t left = 2 * j + 1, right = 2 * j + 2;
      size_t larger = right < count_ && data_[right] > data_[left] ? right : left;
      if (data_[j] < data_[larger]) {
	return false;
      }
    }
  }
  return true;
}

template <class T>
bool Heap<T>::check_recursive_impl(const size_t idx) const
{
  size_t left = 2 * idx + 1, right = 2 * idx + 2;
  if (left >= count_) { return true; }

  size_t larger = right < count_ && data_[right] > data_[left] ? right : left;
  if (data_[idx] < data_[larger]) {
    return false;
  }
  return right < count_ ? check_recursive_impl(left) && check_recursive_impl(right) : true;
}

template <class T>
vector<T> Heap<T>::k_largest_impl(const size_t k) const
{
  vector<T> result;
  priority_queue<pair<size_t,T>,vector<pair<size_t,T> >,Heap_Compare<T> > mh;
  mh.push({0, data_[0]});

  for (size_t i = 0; i < k; ++i) {
    size_t idx = mh.top().first;
    result.push_back(mh.top().second);
    mh.pop();

    size_t left = 2 * idx + 1;
    if (left < count_) {
      mh.push({left, data_[left]});
    }

    size_t right = 2 * idx + 2;
    if (right < count_) {
      mh.push({right, data_[right]});
    }
  }

  return result;
}
