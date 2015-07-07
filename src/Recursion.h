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
void parenthesis_helper(int left, int right, string* ans, vector<string>* res);
vector<string> valid_parenthesis(int n);
int coin_combinations(int target);
void phonenumber_helper(const string& digits, const vector<string>& encoding, int i, string* ans, vector<string>* res);
vector<string> phonenumber_letters(const string& digits);

/*! \brief PhoneNumber computes possible encodings for a phone number
 *
 *  My detailed description
 */
class PhoneNumber
{
  void helper(const string& digits, const array<string,10>& encoding, string& ans, vector<string>& result);
  vector<string> compute(const string& digits);
};


/*! \brief PowerSet computes the power set of a vector of ints
 *
 *  My detailed description
 */
class PowerSet
{
  void helper(vector<int>& S, int offset, vector<int>& subset, vector<vector<int> >& result);
  void compute(vector<int>& S);
};

/*! \brief Combination computes combinations of a vector of ints
 *
 *  My detailed description
 */
class Combination
{
  void helper(vector<int>& S, int offset, int k, vector<int>& subset, vector<vector<int> >& result);
  void compute(vector<int>& S, int k);
};

/*! \brief Permutation computes permutations of a vector of ints
 *
 *  My detailed description
 */
class Permutation
{
  void helper(vector<int>& S, int offset, vector<vector<int> >& result);
  vector<vector<int> > compute(vector<int>& S);
  vector<vector<int> > compute_2(vector<int>& S);
};

/*! \brief WordSearch implements a depth first search for a word in a letter board
 *
 *  My detailed description
 */
class WordSearch
{
public:
  bool feasible(const vector<vector<char> >& board, const array<int, 2>& c);
  bool dfs(vector<vector<char> >& board, const string& word, const array<int, 2>& c, int k);
  bool search(vector<vector<char> >& board, string word);
};
