#ifndef MATRIX_H
#define MATRIX_H

#include "MatrixImpl.h"

class Matrix
{
public:
  Matrix(size_t rows, size_t cols, Depth d) : _depth(d) {
    switch(_depth) {
      case Depth::UINT8  : _a = make_shared<MatType<uint8_t>::array_type>(boost::extents[rows][cols]); break;
      case Depth::FLOAT  : _a = make_shared<MatType<float  >::array_type>(boost::extents[rows][cols]); break;
      case Depth::DOUBLE : _a = make_shared<MatType<double >::array_type>(boost::extents[rows][cols]); break;
    }
  }

  size_t rows() const { return boost::apply_visitor( rows_visitor(), _a); }
  size_t cols() const { return boost::apply_visitor( cols_visitor(), _a); }
  Depth depth() const { return _depth; }
  size_t width() const { return this->cols(); }
  size_t height() const { return this->rows(); }

  template <class T>
  const T& operator() (size_t row, size_t col) const {
    return (*boost::get<shared_ptr<boost::multi_array<T, 2> > >(_a))[row][col];

  }

  template <class T>
  T& operator() (size_t row, size_t col) {
    return const_cast<T&>(static_cast<const Matrix&>(*this).operator()<T>(row, col));
  }

  vector<int> histogram(size_t num_bins) {
    vector<int> result(num_bins);
    switch(_depth) {
    case Depth::UINT8  : 
      for (size_t i = 0; i < this->rows(); ++i) { 
	for (size_t j = 0; j < this->cols(); ++j) {
	  result[(this->operator()<uint8_t>(i, j) / numeric_limits<uint8_t>::max()) * num_bins]++;
	}
      } 
      break;
    case Depth::FLOAT  : 
      for (size_t i = 0; i < this->rows(); ++i) { 
	for (size_t j = 0; j < this->cols(); ++j) {
	  result[(this->operator()<float>(i, j) / numeric_limits<float>::max()) * num_bins]++;
	}
      } 
      break;
    case Depth::DOUBLE  : 
      for (size_t i = 0; i < this->rows(); ++i) { 
	for (size_t j = 0; j < this->cols(); ++j) {
	  result[(this->operator()<double>(i, j) / numeric_limits<double>::max()) * num_bins]++;
	}
      } 
      break;
    }
    return result;
  }

private:
  boost::variant<shared_ptr<MatType<uint8_t>::array_type>, shared_ptr<MatType<float>::array_type>, shared_ptr<MatType<double>::array_type> > _a;
  Depth _depth;

  struct rows_visitor : boost::static_visitor<size_t> {
    template <class T> size_t operator() (const shared_ptr<boost::multi_array<T, 2> >& a) const { return (a->shape())[0]; }
  };
  struct cols_visitor : boost::static_visitor<size_t> {
    template <class T> size_t operator() (const shared_ptr<boost::multi_array<T, 2> >& a) const { return (a->shape())[1]; }
  };

};

#endif
