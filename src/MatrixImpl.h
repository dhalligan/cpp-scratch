#ifndef MATRIXIMPL_H
#define MATRIXIMPL_H

#include <vector>
#include <stdexcept>
#include <string>

#include <boost/variant.hpp>
#include <boost/multi_array.hpp>

using std::vector;
using std::string;
using std::shared_ptr;
using std::make_shared;
using std::numeric_limits;

enum class Depth {UINT8 = 0, FLOAT = 1, DOUBLE = 2};

template <Depth d> struct DepthType;
template <>        struct DepthType<Depth::UINT8 > { typedef uint8_t type; };
template <>        struct DepthType<Depth::FLOAT > { typedef float   type; };
template <>        struct DepthType<Depth::DOUBLE> { typedef double  type; };

template <class T> struct MatType          { typedef boost::multi_array<T, 2> array_type; };
template <>        struct MatType<uint8_t> { typedef boost::multi_array<uint8_t, 2> array_type; static const Depth type = Depth::UINT8; };
template <>        struct MatType<float  > { typedef boost::multi_array<float,   2> array_type; static const Depth type = Depth::FLOAT; };
template <>        struct MatType<double > { typedef boost::multi_array<double,  2> array_type; static const Depth type = Depth::DOUBLE; };

template<class T>
class MatrixImpl
{
public:
  MatrixImpl(size_t rows = 0, size_t cols = 0) : data(vector<vector<T> >(rows, vector<T>(cols))) {}

  size_t rows() const { return data.size(); }
  size_t cols() const { return data.front().size(); }

  const T& operator() (size_t row, size_t col) const {
    if (row < 0 || row > this->rows() || col < 0 || col > this->cols()) {
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
