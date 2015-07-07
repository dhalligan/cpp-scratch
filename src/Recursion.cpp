#include "Recursion.h"

int CountPermutation::compute_recursive(int n)
{
  if (n < 0) { return 0; }
  if (n == 0) { return 1; }

  return
    compute_recursive(n - 3) +
    compute_recursive(n - 2) +
    compute_recursive(n - 1);
}

int CountPermutation::compute_memoize(int k, vector<int>& score_ways)
{
  vector<int> permutations (k + 1, 0);
  if (k < 0) { return 0; }
  if (k == 0) { return 1; }

  if (permutations[k] > -1) {
    return permutations[k];
  } else {
    permutations[k] =
      compute_memoize(k - 3, score_ways) +
      compute_memoize(k - 2, score_ways) +
      compute_memoize(k - 1, score_ways);
    return permutations[k];
  }
}

int CountPermutation::compute(int k, vector<int>& score_ways)
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

int CountCombination::compute(int k, vector<int>& score_ways)
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

void Parenthesis::helper(int left, int right, string* ans, vector<string>* res)
{
  if (left < 0 || right < left) { return; }

  if (left == 0 && right == 0) {
    res->emplace_back(*ans);
    return;
  }

  if (left > 0) {
    ans->push_back('(');
    helper(left - 1, right, ans, res);
    ans->pop_back();
  }

  if (right > 0) {
    ans->push_back(')');
    helper(left, right - 1, ans, res);
    ans->pop_back();
  }
}

vector<string> Parenthesis::compute(int n)
{
  if (n == 0) { return vector<string>{}; }
  string ans;
  vector<string> result;
  helper(n, n, &ans, &result);
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

void PhoneNumber::helper(const string& digits, const array<string,10>& encoding, string& ans, vector<string>& result)
{
  if (ans.size() == digits.size()) {
    result.emplace_back(ans);
    return;
  }
  for (const char& c : encoding[digits[ans.size()] - '0']) {
    ans.push_back(c);
    helper(digits, encoding, ans, result);
    ans.pop_back();
  }
}

vector<string> PhoneNumber::compute(const string& digits)
{
  if (digits.empty()) { return {}; }
  const array<string,10> encoding {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  string ans;
  vector<string> result;
  helper(digits, encoding, ans, result);
  return result;
}

bool WordSearch::feasible(const vector<vector<char> >& board, const array<int, 2>& c)
{
  return 0 <= c[0] && c[0] < board.size() && 0 <= c[1] && c[1] < board.front().size() && board[c[0]][c[1]] != ' ';
}

bool WordSearch::dfs(vector<vector<char> >& board, const string& word, const array<int, 2>& c, int k)
{
  int i = c[0], j = c[1];
  if (board[i][j] != word[k]) { return false; }
  if (k == word.size() - 1) { return true; }

  char letter = word[k];
  board[i][j] = ' ';
  const array<array<int, 2>, 4> next {{ {{i + 1, j}}, {{i, j + 1}}, {{i - 1, j}}, {{i, j - 1}} }};
  for (const auto& n : next) {
    if (feasible(board, n) && dfs(board, word, n, k + 1)) { return true; }
  }
  board[i][j] = letter;
  return false;
}

bool WordSearch::search(vector<vector<char> >& board, string word)
{
  for (int i = 0; i < board.size(); ++i) {
    for (int j = 0; j < board.front().size(); ++j) {
      if (dfs(board, word, array<int, 2> {{i, j}}, 0)) { return true; }
    }
  }
  return false;
}

void PowerSet::helper(vector<int>& S, int offset, vector<int>& subset, vector<vector<int> >& result)
{
  if (!subset.empty()) {
    result.emplace_back(subset);
  }

  for (int i = offset; i < S.size(); ++i) {
    subset.emplace_back(S[i]);
    helper(S, offset + 1, subset, result);
    subset.pop_back();
  }
}

void PowerSet::compute(vector<int>& S)
{
  vector<int> subset;
  vector<vector<int> > result;
  helper(S, 0, subset, result);
}

void Combination::helper(vector<int>& S, int offset, int k, vector<int>& subset, vector<vector<int> >& result)
{
  if (k == 0) {
    result.emplace_back(subset);
    return;
  }

  for (int i = offset; i < S.size(); ++i) {
    subset.emplace_back(S[i]);
    helper(S, offset + 1, k - 1, subset, result);
    subset.pop_back();
  }
}

void Combination::compute(vector<int>& S, int k)
{
  vector<int> subset;
  vector<vector<int> > result;
  helper(S, 0, k, subset, result);
}

void Permutation::helper(vector<int>& S, int offset, vector<vector<int> >& result)
{
  if (offset == S.size()) {
    result.emplace_back(S);
    return;
  } else {
    for (int j = offset; j < S.size(); ++j) {
      swap(S[offset], S[j]);
      helper(S, offset + 1, result);
      swap(S[offset], S[j]);
    }
  }
}

vector<vector<int> > Permutation::compute(vector<int>& S)
{
  vector<vector<int> > result;
  helper(S, 0, result);
  return result;
}

vector<vector<int> > Permutation::compute_2(vector<int>& S)
{
  vector<vector<int> > result;
  sort(S.begin(), S.end());
  do { result.emplace_back(S); } while (next_permutation(S.begin(), S.end()));
  return result;
}
