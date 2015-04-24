#include "Recursion.h"

int count_permutations_1(int n)
{
  if (n < 0) { return 0; }
  if (n == 0) { return 1; }

  return 
    count_permutations_1(n - 3) +
    count_permutations_1(n - 2) +
    count_permutations_1(n - 1);
}

int count_permutations_2(int k, vector<int>& score_ways)
{
  vector<int> permutations (k + 1, 0);
  if (k < 0) { return 0; }
  if (k == 0) { return 1; }

  if (permutations[k] > -1) {
    return permutations[k];
  } else {
    permutations[k] = 
      count_permutations_2(k - 3, score_ways) + 
      count_permutations_2(k - 2, score_ways) +
      count_permutations_2(k - 1, score_ways);
    return permutations[k];
  }
}

int count_permutations_3(int k, vector<int>& score_ways)
{
  vector<int> permutations (k + 1, 0);
  permutations[0] = 1;
  for (int i = 0; i <= k; ++i) {
    for (const int& score : score_ways) {
      if (i >= score) {
	permutations[i] += permutations[i - score];
      }
    }
  }
  return permutations[k];
}

int count_combinations(int k, vector<int>& score_ways)
{
  vector<int> combinations (k + 1, 0);
  combinations[0] = 1;
  for (const int& score : score_ways) {
    for (int i = 0; i <= k; ++i) {
      if (i >= score) {
	combinations[i] += combinations[i - score];
      }
    }
  }
  return combinations[k];
}

void parenthesis_helper(int left, int right, string* ans, vector<string>* res)
{
  if (left < 0 || right < left) { return; }

  if (left == 0 && right == 0) { 
    res->emplace_back(*ans); 
    return; 
  }

  if (left > 0) {
    ans->push_back('(');
    parenthesis_helper(left - 1, right, ans, res);
    ans->pop_back();
  }
  
  if (right > 0) {
    ans->push_back(')');
    parenthesis_helper(left, right - 1, ans, res);
    ans->pop_back();
  }
  
}

vector<string> valid_parenthesis(int n) 
{
  if (n == 0) { return vector<string>{}; }
  string ans;
  vector<string> result;
  parenthesis_helper(n, n, &ans, &result);
  return result;
}

int coin_combinations(int n)
{
  vector<int> coin_values {1, 5, 10, 25};
  vector<int> sums(n + 1, 0);
  sums[0] = 1;

  for (const int& v : coin_values) {
    for (int s = v; s <= n; ++s) {
      sums[s] += sums[s - v];
    }
  }
  return sums[n];
}

void phonenumber_helper(const string& digits, const vector<string>& encoding, int i, string* ans, vector<string>* res)
{
  if (i == digits.size()) {
    res->emplace_back(*ans);
    return;
  }
  for (const char c : encoding[digits[i] - '0']) {
    ans->push_back(c);
    phonenumber_helper(digits, encoding, i + 1, ans, res);
    ans->pop_back();
  }
}

vector<string> phonenumber_letters(const string& digits)
{
  string ans;
  vector<string> result;
  const vector<string> encoding {"0", "1", "2abc", "3def", "4ghi", "5jkl", "6mno", "7pqrs", "8tuv", "9wxyz"};
  phonenumber_helper(digits, encoding, 0, &ans, &result);
  return result;
}
