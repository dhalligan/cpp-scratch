#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <stdexcept>
#include <string>

#include <boost/variant.hpp>

#include "MatrixImpl.h"

using std::vector;
using std::string;
using std::shared_ptr;
using std::make_shared;

class Matrix
{
public:
  Matrix(size_t w, size_t h, size_t d) : _depth(d) {
    if (d == 1) {
      _m = make_shared<MatrixImpl<uint8_t> >(w, h);
    } else {
      _m = make_shared<MatrixImpl<float> >(w, h);
    }
  }

  size_t width() const { return boost::apply_visitor( width_visitor(), _m); }
  size_t height() const { return boost::apply_visitor( height_visitor(), _m); }
  size_t depth() const { return _depth; }

  template <class T>
  const T& operator() (size_t row, size_t col) const {
    return boost::get<shared_ptr<MatrixImpl<T> > >(_m)->operator()(row, col);
  }

  template <class T>
  T& operator() (size_t row, size_t col) {
    return const_cast<T&>(static_cast<const Matrix&>(*this).operator()<T>(row, col));
  }

  // vector<int> histogram(int num_bins) {
  //   if (!_depth) { throw std::out_of_range("that depth isn't supported"); }
  //   return _uint8_matrix.histogram(num_bins);
  // }

private:
  boost::variant<shared_ptr<MatrixImpl<uint8_t> >, shared_ptr<MatrixImpl<float> > > _m;
  size_t _depth;

  struct width_visitor : boost::static_visitor<size_t> {
    template <class T> size_t operator() (const shared_ptr<MatrixImpl<T> >& m) const { return m->width(); }
  };
  struct height_visitor : boost::static_visitor<size_t> {
    template <class T> size_t operator() (const shared_ptr<MatrixImpl<T> >& m) const { return m->height(); }
  };

};

#endif
