#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using std::vector;
using std::unordered_map;
using std::cout;
using std::endl;
using std::pair;
using std::max;
using std::min;

int binary_search(const vector<int>& A, int t);
pair<int, int> binary_search_2d(const vector<vector<int> >& A, int t);
int majority_element(const vector<int>& A);
vector<int> two_sum(const vector<int>& vec, int target);
bool two_sum_sorted(const vector<int>& A, int k);
bool three_sum_sorted(vector<int>& A, int k);
vector<vector<int> > three_sum(vector<int> &num);
void merge_two_sorted_arrays_1(int A[], int m, int B[], int n);
int start_city(const vector<int>& gas, const vector<int>& cost);
pair<int,pair<int,int> > water_trapped_two_indices(const vector<int>& A);
int water_tapped(const vector<int>& A);

template <class T>
int binary_search(const T& k, const vector<T>& A)
{
  int L = 0, U = A.size() - 1;
  int R = -1;
  while (L <= U) {
    int M = (L < 0) == (U < 0) ? L + (U - L) / 2 : (L + U) / 2;
    if (A[M] < k) {
      L = M + 1;
    } else if (A[M] == k) {
      R = M; U = M - 1;
    } else {
      U = M - 1;
    }
  }
  return R;
}

// Min value of circular array *assuming no repeats*
template <class T>
int binary_search_min_circular(const vector<T>& A)
{
  int L = 0, U = A.size() - 1;
  while (L < U) {
    int M = (L < 0) == (U < 0) ? L + (U - L) / 2 : (L + U) / 2;
    if (A[M] > A[U]) {
      L = M + 1;
    } else {
      U = M;
    }
  }
  return L;
}

template <class T>
int binary_search_circular_1(const T& k, const vector<T>& A)
{
  int L = 0, U = A.size() - 1;
  int M = binary_search_min_circular(A);
  if (k > A[U]) {
    return binary_search(k, vector<int>(A.cbegin(), A.cbegin() + M));
  } else {
    return M + binary_search(k, vector<int>(A.cbegin() + M, A.cend()));
  }
}

template <class T>
int binary_search_circular_2(const T& k, const vector<T>& A)
{
  int L = 0, U = A.size() - 1;
  while (L <= U) {
    int M = (L < 0) == (U < 0) ? L + (U - L) / 2 : (L + U) / 2;
    if (A[M] == k) {
      return M;
    } else if (A[M] <= A[U]) {
      if (A[M] < k && k <= A[U]) {
	L = M + 1;
      } else {
	U = M - 1;
      }
    } else {
      if (A[L] <= k && k < A[M]) {
	U = M - 1;
      } else {
	L = M + 1;
      }
    }
  }
  return -1;
}
