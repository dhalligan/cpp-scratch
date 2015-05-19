#include "ArrayUtil.h"

int binary_search(const vector<int>& A, int t)
{
  int l = 0, u = A.size() - 1, r = -1;
  while (l <= u) {
    int m = l + (u - l) / 2;
    if (A[m] >= t) {
      r = m, u = m - 1;
    } else {
      l = m + 1;
    }
  }
  return r;
}

int majority_element(const vector<int>& A)
{
  int count = 0, cand = A.front();
  for (int i = 0; i < A.size(); ++i) {
    if (count == 0) {
      cand = A[i];
      count = 1;
    } else if (A[i] == cand) {
      count++;
    } else {
      count--;
    }
  }
  return cand;
}

// two_sum returns the 1-based indices of two numbers in the vector vec adding up to target
vector<int> two_sum(const vector<int>& vec, int target)
{
  vector<int> numbers(vec);
  sort(numbers.begin(), numbers.end());
  int i = 0, j = numbers.size() - 1;

  while (i < j) {
    int value = numbers[i] + numbers[j];
    if (value == target) {
      int ii = 0, jj = 0;
      for ( ; ii < vec.size(); ++ii) {
	if (vec[ii] == numbers[i]) { break; }
      }
      for ( ; jj < vec.size(); ++jj) {
	if (vec[jj] == numbers[j] && jj != ii ) { break; }
      }
      return {ii < jj ? ii + 1 : jj + 1, ii < jj ? jj + 1 : ii + 1};
    } else if (value < target) {
      do { i++; } while (numbers[i] == numbers[i - 1]);
    } else {
      do { j--; } while (numbers[j] == numbers[j + 1]);
    }
  }
  return {0, 0};
}

vector<vector<int> > three_sum(vector<int> &num) {
  if (num.size() < 3) { return {}; }
  sort(num.begin(), num.end());
  vector<vector<int> > result;
  int i = 0;
  while (i < num.size() - 2) {
    int target = -num[i];
    int j = i + 1, k = num.size() - 1;
    while (j < k) {
      int value = num[j] + num[k];
      if (value == target) {
	result.emplace_back(vector<int>{num[i], num[j], num[k]});
	do { j++; } while (num[j] == num[j - 1] && j < k);
	do { k--; } while (num[k] == num[k + 1] && j < k);
      } else if (value < target) {
	do { j++; } while (num[j] == num[j - 1] && j < k);
      } else {
	do { k--; } while (num[k] == num[k + 1] && j < k);
      }
    }
    do { i++; } while (num[i] == num[i-1] && i < num.size() - 2);
  }
  return result;
}

bool two_sum_sorted(const vector<int>& A, int k)
{
  int i = 0, j = A.size() - 1;
  while (i < j) {
    int sum = A[i] + A[j];
    if (sum == k) {
      return true;
    } else if (sum > k) {
      j--;
    } else {
      i++;
    }
  }
  return false;
}

bool three_sum_sorted(vector<int>& A, int k)
{
  for (int i = 0; i < A.size(); ++i) {
    if (two_sum_sorted(A, k - A[i])) {
      return true;
    }
  }
  return false;
}

// A has enough space to hold B at the end
void merge_two_sorted_arrays_1(int A[], int m, int B[], int n)
{
  int a = m - 1, b = n - 1, tar = m + n - 1;
  while (a >= 0 && b >= 0) {
    A[tar--] = A[a] > B[b] ? A[a--] : B[b--];
  }
  while (b >= 0) {
    A[tar--] = B[b--];
  }
}

int start_city(const vector<int>& gas, const vector<int>& cost)
{
  int carry = 0;
  pair<size_t,int> city_carry_pair {0, 0};
  for (size_t i = 1; i < gas.size(); ++i) {
    carry += gas[i - 1] - cost[i - 1];
    if (carry < city_carry_pair.second) {
      city_carry_pair = {i, carry};
    }
  }
  carry += gas[gas.size() - 1] - cost[gas.size() - 1];
  return carry >= 0 ? city_carry_pair.first : -1;
}

pair<int,pair<int,int> > water_trapped_two_indices(const vector<int>& A)
{
  int i = 0, j = A.size()-1;
  int max_trapped = 0, max_i = i, max_j = j;

  while (i < j) {
    int trapped = min(A[i], A[j]) * static_cast<int>(j - i);
    if (trapped > max_trapped) {
      max_trapped = trapped;
      max_i = i, max_j = j;
    }
    if (A[i] < A[j]) {
      i++;
    } else if (A[i] > A[j]) {
      j--;
    } else {
      i++, j--;
    }
  }
  return {max_trapped, {max_i, max_j}};
}

int water_tapped(const vector<int>& A)
{
  int h_max = distance(A.begin(), max_element(A.begin(), A.end()));

  int sum = 0, rmax = 0;
  for (int i = 0; i < h_max; ++i) {
    rmax = max(rmax, A[i]);
    sum += rmax - A[i];
  }

  rmax = 0;
  for (int i = A.size() - 1; i > h_max; --i) {
    rmax = max(rmax, A[i]);
    sum += rmax - A[i];
  }

  return sum;
}
