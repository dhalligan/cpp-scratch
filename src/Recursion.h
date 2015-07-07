#include <vector>
#include <string>
#include <array>
#include <algorithm>

using std::vector;
using std::string;
using std::array;
using std::swap;

int unit_test_func(int x);

int count_permutations_1(int n);
int count_permutations_2(int k, vector<int>& score_ways);
int count_permutations_3(int k, vector<int>& score_ways);
int count_combinations(int k, vector<int>& score_ways);
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
  vector<vector<int> > compute_2(vector<int>& S);
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
