#include <vector>
#include <string>
#include <array>

using std::vector;
using std::string;
using std::array;

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

