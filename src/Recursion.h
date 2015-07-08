#include <vector>
#include <string>
#include <array>
#include <algorithm>

using std::vector;
using std::string;
using std::array;
using std::swap;
using std::pair;

/*! \brief CountPermutation computes the number of permutations of a set of objects that add up to a target value
 *
 * My detailed description
 */
class CountPermutation
{
public:
  int compute(int k, vector<int>& score_ways);
};

/*! \brief CountCombination computes the number of combinations of a set of objects that add up to a target value
 *
 * My detailed description
 */
class CountCombination
{
public:
  int compute(int k, vector<int>& score_ways);
};

int coin_combinations(int target);

/*! \brief Parenthesis computes possible valid arrangements of parenthesis
 *
 *  My detailed description
 */
class Parenthesis
{
public:
  vector<string> compute(int n);
private:
  void helper(int left, int right, string* ans, vector<string>* res);
};

/*! \brief PhoneNumber computes possible encodings for a phone number
 *
 *  My detailed description
 */
class PhoneNumber
{
public:
  vector<string> compute(const string& digits);
private:
  void helper(const string& digits, const array<string,10>& encoding, string& ans, vector<string>& result);
};


/*! \brief PowerSet computes the power set of a vector of ints
 *
 *  My detailed description
 */
class PowerSet
{
public:
  void compute(vector<int>& S);
private:
  void helper(vector<int>& S, int offset, vector<int>& subset, vector<vector<int> >& result);
};

/*! \brief Combination computes combinations of a vector of ints
 *
 *  My detailed description
 */
class Combination
{
public:
  void compute(vector<int>& S, int k);
private:
  void helper(vector<int>& S, int offset, int k, vector<int>& subset, vector<vector<int> >& result);
};

/*! \brief Permutation computes permutations of a vector of ints
 *
 *  My detailed description
 */
class Permutation
{
public:
  vector<vector<int> > compute(vector<int>& S);
  vector<vector<int> > compute_stl(vector<int>& S);
private:
  void helper(vector<int>& S, int offset, vector<vector<int> >& result);
};

/*! \brief WordSearch implements a depth first search for a word in a letter board
 *
 *  My detailed description
 */
class WordSearch
{
public:
  bool search(vector<vector<char> >& board, string word);
private:
  bool feasible(const vector<vector<char> >& board, const array<int, 2>& c);
  bool dfs(vector<vector<char> >& board, const string& word, const array<int, 2>& c, int k);
};

/*! \brief Fibonacci computes Fibonacci numbers
 *
 * My detailed description
 */
class Fibonacci
{
public:
  int compute(int n);
  int compute_dp(int n);
private:
  pair<int,int> helper(int n);
};

/*! \brief Factorial computes factorials
 *
 * My detailed description
 */
class Factorial
{
public:
  unsigned long long int compute(unsigned int n);
  unsigned long long int compute_recursive(unsigned int n);
  unsigned long long int compute_tail_recursive(unsigned int n);
  unsigned long long int  helper(unsigned int n, unsigned long long int acc);
};

/*! \brief Fact computes factorials via a template metaprogram
 *
 * My detailed description
 */
template <unsigned long long int n>
struct Fact {
  enum { value = n * Fact<n - 1>::value };
};

template <>
struct Fact<0> {
  enum { value = 1 };
};

/*! \brief SquareRootFloat computes floating point square roots with a binary search
 *
 * My detailed description
 */
class SquareRootFloat
{
public:
  double compute(double x);
private:
  int compare(double x, double y);
};

/*! \brief SquareRootInt computes integer square roots with a binary search
 *
 * My detailed description
 */
class SquareRootInt
{
public:
  int compute(int x);
};
