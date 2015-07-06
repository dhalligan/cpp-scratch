#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <string>

using std::vector;
using std::string;

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

class Matrix
{
public:
  Matrix(size_t w, size_t h, bool d) : _uint8_matrix{d ? w : 0, d ? h : 0}, _float_matrix{d ? 0 : w, d ? 0 : h}, _width(w), _height(h), _depth(d) { }

  size_t width() const { return _width; }
  size_t height() const { return _height; }
  bool depth() const { return _depth; }

  const uint8_t& get_uint8(size_t row, size_t col) const { return _uint8_matrix(row, col); }
  uint8_t& get_uint8(size_t row, size_t col) { return _uint8_matrix(row, col); }

  const float& get_float(size_t row, size_t col) const { return _float_matrix(row, col); }
  float& get_float(size_t row, size_t col) { return _float_matrix(row, col); }

  vector<int> histogram(int num_bins) {
    if (!_depth) { throw std::out_of_range("that depth isn't supported"); }
    return _uint8_matrix.histogram(num_bins);
  }

private:

  MatrixImpl<uint8_t> _uint8_matrix;
  MatrixImpl<float> _float_matrix;
  size_t _width, _height;
  bool _depth;

};

#endif
