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
bool word_search_feasible(const vector<vector<char> >& board, const array<int, 2>& c);
bool word_search_dfs(vector<vector<char> >& board, const string& word, const array<int, 2>& c, int k);
bool word_search(vector<vector<char> >& board, string word);
void powerset_helper(vector<int>& S, int offset, vector<int>& subset, vector<vector<int> >& result);
void powerset(vector<int>& S);
void combination_helper(vector<int>& S, int offset, int k, vector<int>& subset, vector<vector<int> >& result);
void combination(vector<int>& S, int k);
void permutation_helper(vector<int>& S, int offset, vector<vector<int> >& result);
vector<vector<int> > permutation(vector<int>& S);
vector<vector<int> > permutation_2(vector<int>& S);
