#ifndef MATRIXIMPL_H
#define MATRIXIMPL_H

#include <vector>
#include <stdexcept>
#include <string>

using std::vector;
using std::string;

template <class T>
struct MatType;

template <>
struct MatType<uint8_t>
{
  static const int type = 1;
};

template <>
struct MatType<float>
{
  static const int type = 0;
};

template<class T>
class MatrixImpl
{
public:
  MatrixImpl(size_t width = 0, size_t height = 0) : data(vector<vector<T> >(height, vector<T>(width))) {}

  size_t width() const { return data.front().size(); }

  size_t height() const { return data.size(); }

  const T& operator() (size_t row, size_t col) const {
    if (row < 0 || row > this->height() || col < 0 || col > this->width()) {
      throw std::out_of_range("indices out of bounds");
    }
    return data[row][col];
  }

  T& operator() (size_t row, size_t col) {
    return const_cast<T&>(static_cast<const MatrixImpl&>(*this)(row, col));
  }

  // This only works for the uint8_t right now
  vector<int> histogram(int num_bins) const {
    vector<int> result(num_bins);
    int range = 256;
    int bin_size = range / num_bins;
    for (const auto& r : data) {
      for (auto v : r) {
	result[v / bin_size]++;
      }
    }
    return result;
  }

private:
  vector<vector<T> > data;

};

#endif
