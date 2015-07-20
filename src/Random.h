#ifndef RANDOM_H
#define RANDOM_H

#include <random>

using std::default_random_engine;
using std::uniform_int_distribution;

/*! \brief Rand_int randomly generates an integer in the given range
 *
 *  My detailed description
 */
class Rand_int 
{
 public:
  Rand_int(int low, int high) : dist{low, high} {}
  int operator() () { return dist(re); }
  private:
  
  default_random_engine re;
  uniform_int_distribution<> dist;
};

#endif
