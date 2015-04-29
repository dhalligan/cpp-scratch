// <Copyright Holder>. Copyright (C) <Copyright Year(s)>. <License>.
#ifndef HEADER_SRC_APP_H_INCLUDED
#define HEADER_SRC_APP_H_INCLUDED

#include <boost/shared_ptr.hpp>
#include <vector>
#include <list>
#include <array>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <fstream>
#include <stack>
#include <exception>
#include <stdexcept>
#include <queue>
#include <deque>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <set>
#include <bitset>
#include <memory>
#include <chrono>
#include <thread>

#include "BST.h"
#include "List.h"
#include "Heap.h"
#include "StringUtil.h"
#include "Thread.h"
#include "Random.h"
#include "CircularVector.h"
#include "Queue.h"
#include "Stack.h"
#include "QueueTwoStacks.h"
#include "StackSet.h"
#include "MaxStack.h"
#include "MaxQueue.h"
#include "StackUtil.h"
#include "LRUCache.h"
#include "Algorithm.h"
#include "BitUtil.h"
#include "ArrayUtil.h"
#include "GraphUtil.h"
#include "Recursion.h"

using std::shared_ptr;
using std::unique_ptr;
using std::vector;
using std::array;
using std::string;
using std::stringstream;
using std::pair;
using std::tuple;
using std::less;
using std::greater;
using std::list;
using std::unordered_map;
using std::unordered_set;
using std::queue;
using std::deque;
using std::stack;
using std::set;
using std::length_error;
using std::max;
using std::min;
using std::bitset;
using std::ifstream;
using namespace std::chrono;
using namespace StringUtil;
using namespace Algorithm;

constexpr double my_square(const double x) { return x * x; };

struct ColoredVertex
{
  enum Color { white, gray, black } color;
  vector<ColoredVertex*> edges;
};

struct DLVertex
{
  int d, l;
  vector<DLVertex*> edges;
};



template <class T>
struct BinaryTreeNode {
  T data;
  unique_ptr<BinaryTreeNode<T> > left, right;
};

template <class T>
struct BinaryTreeNode2 {
  T data;
  unique_ptr<BinaryTreeNode2<T> > left, right;
  BinaryTreeNode2<T>* parent;
};

template <class T>
struct BinaryTreeNode3 {
  T data;
  unique_ptr<BinaryTreeNode3<T> > left, right;
  size_t size;
};


template <class T>
struct Coordinate {
  bool operator== (const Coordinate& that) const {
    return x == that.x && y == that.y;
  }
  T x, y;
};

template <class T>
struct GraphVertex {
  T label;
  vector<GraphVertex*> edges;
};

template <class T>
struct GraphVertex2 {
  T d = -1;
  vector<GraphVertex2<T>* > edges;
};

template <class T>
struct SGraphVertex {
  T label;
  vector<shared_ptr<SGraphVertex<T> > > edges;
};

template <class T>
struct TreeVertex {
  T data;
  vector<pair<unique_ptr<TreeVertex<T> >, double> > edges;
};


class TournamentTree
{
public:
  TournamentTree(int n) : tree_(vector<TreeNode>(2*n-1)) {}
  void insert (int item, double cap) {
    insert_helper(0, item, cap);
  }

private:
  struct TreeNode {
    double cap = 1.0;
    vector<int> items;
  };

  vector<TreeNode> tree_;
  void insert_helper(int idx, int item, double cap) {
    int left = 2*idx + 1, right = 2*idx + 2;
    if (left < tree_.size()) {
      // interior node
      insert_helper(tree_[left].cap >= cap ? left : right, item, cap);
      tree_[idx].cap = max(tree_[left].cap, tree_[right].cap);
    } else {
      // leaf node
      tree_[idx].items.emplace_back(item);
      tree_[idx].cap -= cap;
    }
  }
};

class Star {
public:
  double distance() const {return std::sqrt(x_*x_ + y_*y_ + z_*z_);};
  bool operator<(const Star& s) const {return distance() < s.distance();};
  int id;
  double x_, y_, z_;
};

struct Event_Point
{
  bool operator< (const Event_Point& e) const {
    return time != e.time ? time < e.time : (is_start && !e.is_start);
  }

  int time;
  bool is_start;
};

struct Interval
{
  int left;
  int right;
};

struct Interval2
{
private:
  struct Endpoint
  {
    int val;
    bool closed;
  };

public:
  bool operator< (const Interval2& i) const { left.val != i.left.val ? left.val < i.left.val : left.closed && !i.left.closed; }
  Endpoint left, right;

};

struct OCInterval
{
  int left, right;
  bool open_l, open_r;
};

template <class T>
struct Item
{
  T value;
  T weight;
};

template <class T, class V>
struct knapsack_combinations_op
{
  T operator() (T t1, T t2, V v) {
    return t1 + t2;
  }
};

template <class T>
struct Max_Op
{
  static const T identity = -std::numeric_limits<T>::infinity;
  T operator() (T t1, T t2) { return std::max(t1, t2); }
};

template <class T>
struct Add_Op
{
  static const T identity = 0;
  T operator() (T t1, T t2) { return t1 + t2; }
};

template <class T>
struct Mult_Op
{
  static const T identity = 1;
  T operator() (T t1, T t2) { return t1 * t2; }
};

struct Num
{
  Num(int a, int b) : a_(a), b_(b), value_(a + b * sqrt(2)) {}
  bool operator< (const Num& that) const { return value_ < that.value_; }
  double value_;
  int a_, b_;
};

class App
{
 public:
  App(int& argc, char** argv);
  ~App();

  int exec();

 private:

};

class letter
{
public:
  letter() : n(1) {};
  letter(const char c) : n(c - 'A' + 1)  {};
  operator int () const {return n;};
private:
  int n;
};

//
// Compute z = k*x + y
//
template<class TX, class TY>
class kxpy
{
public:
  kxpy(const TX k) : k_(k) {};
  TX operator() (const TX x, const TY y) { return k_ * x + y; };

private:
  TX k_;
};

//
// Compute z = k*x + y
//
template<class TX, class TY, class ADD, class MULT>
class AXPY
{
public:
  AXPY(const TX a) : a_(a) {};
  TX operator() (const TX x, const TY y) { return add_(mult_(a_, x), y); };

private:
  TX a_;
  ADD add_;
  MULT mult_;
};


template<class ForwardIt, class TX, class TY>
class Polynomial
{
public:
  Polynomial(ForwardIt first, ForwardIt last) : first_(first), last_(last)  {};
  TX operator() (const TX p) { return accumulate( first_, last_, 0, kxpy<TX,TY>(p) ); };

private:
  ForwardIt first_;
  ForwardIt last_;
};

class Parity
{
 public:
  Parity();

  unsigned short p1(unsigned long long x);
  unsigned short p2(unsigned long long x);
  unsigned short p3(unsigned long long x);
  unsigned short p4(unsigned long long x);

  unsigned short reverse_short_bits(unsigned short x);
  unsigned long long reverse_bits(unsigned long long x);
  long long swap_bits(long long x, int i, int j);

 private:
  std::unordered_map<unsigned short,unsigned short> sixteenBitParityTable;
  std::unordered_map<unsigned short,unsigned short> sixteenBitReverseTable;
  unsigned short fourBitParityTable;
};


string compress_string(string& s);
string compress_string_2(string& s);

int string_to_integer(const std::string& s, const int base);
//std::string integer_to_string(const int n, const int base);

//std::string convert_base(const std::string& s, const int base1, const int base2);

int ssDecodeColID(const std::string& s);

unsigned long long closest_int_same_bits(unsigned long long x);
unsigned long long next_int_same_bits(unsigned long long n);
unsigned long long previous_int_same_bits(unsigned long long n);

void print_fraction_binary(double x);

double power(double x, int y);

int smallest_missing_positive(std::vector<int>& v);

int max_forward_diff(const std::vector<int>& v);

int max_forward_diff_2(const std::vector<int>& v);

bool palindromic(std::string s);

void remove_replace(std::string& s, char remove, char replace, char with);

std::string reverse_sentence(const std::string& s);

std::vector<std::string> tokenize_sentence(const std::string& s);

void phone_mnemonic_helper(const std::string& number, int d, std::string* ans);

void print_linked_list(const shared_ptr<ListNode<int> >& node);

void append_node(const shared_ptr<ListNode<int> >& node, shared_ptr<ListNode<int> >* head, shared_ptr<ListNode<int> >* tail);
void prepend_node(const shared_ptr<ListNode<int> >& node, shared_ptr<ListNode<int> >* head);

void append_node_and_advance(shared_ptr<ListNode<int> >* node, shared_ptr<ListNode<int> >* head, shared_ptr<ListNode<int> >* tail);

shared_ptr<ListNode<int> > merge(shared_ptr<ListNode<int> > F, shared_ptr<ListNode<int> > L);

shared_ptr<ListNode<int> > reverse_list(const shared_ptr<ListNode<int> >& F);

shared_ptr<ListNode<int> > reverse_sublist(const shared_ptr<ListNode<int> >& L, int s, int f);

shared_ptr<ListNode<int> > find_cycle(shared_ptr<ListNode<int> > L);

void delete_node_from_list(const shared_ptr<ListNode<int> >& v);
void delete_next_node_from_list(const shared_ptr<ListNode<int> >& v);

void remove_kth_last_from_list(int k, const shared_ptr<ListNode<int> >& L);

double find_median_sorted_list(const shared_ptr<ListNode<int> >& L);
bool palindromic_list(shared_ptr<ListNode<int> >& L);

void unique_list(const shared_ptr<ListNode<int> >& L);

int eval(const std::string& s);

bool pbb(const std::string& s);

int match_length(const std::string& s);

void insert(int e, std::stack<int>& s);
void sort(std::stack<int>& s);

int height(const unique_ptr<BinaryTreeNode<int> >& T);
bool balanced(const unique_ptr<BinaryTreeNode<int> >& T);

std::pair<BinaryTreeNode<int>*,int> nodes(const unique_ptr<BinaryTreeNode<int> >& T, int k);
BinaryTreeNode<int>* find_non_k_balanced_node(const unique_ptr<BinaryTreeNode<int> >& T, int k);

bool symmetric_match(const unique_ptr<BinaryTreeNode<int> >& L, const unique_ptr<BinaryTreeNode<int> >& R);
bool symmetric(const unique_ptr<BinaryTreeNode<int> >& T);

BinaryTreeNode<int>* lca(const unique_ptr<BinaryTreeNode<int> >& T, const unique_ptr<BinaryTreeNode<int> >& A, const unique_ptr<BinaryTreeNode<int> >& B);
int depth(const BinaryTreeNode2<int>* T);
BinaryTreeNode2<int>* lca2(const unique_ptr<BinaryTreeNode2<int> >& T, const unique_ptr<BinaryTreeNode2<int> >& A, const unique_ptr<BinaryTreeNode2<int> >& B);

int inorder_traversal(const unique_ptr<BinaryTreeNode<int> >& T, int parent_num);
int sum_root_to_leaf_paths(const unique_ptr<BinaryTreeNode<int> >& T);

bool inorder_traversal_2(const unique_ptr<BinaryTreeNode<int> >& T, int parent_num, int target);
int find_root_to_leaf_path(const unique_ptr<BinaryTreeNode<int> >& T, int target);

BinaryTreeNode3<int>* inorder_kth_node(const unique_ptr<BinaryTreeNode3<int> >& T, int k);

void inorder_traversal(const unique_ptr<BinaryTreeNode2<int> >& T);
vector<int> inorder_traversal(const unique_ptr<BinaryTreeNode<int> >& T);

vector<int> merge_arrays(const vector<vector<int> >& S);
vector<int> kid_sort(const vector<int>& v);

void online_median(std::istream& sin);

int k_largest(std::priority_queue<int, vector<int>, less<int> >& mh, int k);

vector<int> k_largest_in_binary_heap(const vector<int>& A, int k);

int binary_search(int e, const vector<int>& A);

int binary_search_fixed_point(const vector<int>& A);

int binary_search_min_circular(const vector<int>& A);
int binary_search_circular(int k, const vector<int>& A);

int square_root_int(int x);
double square_root_float(double x);

void find_anagrams(const vector<string>& dictionary);
void find_palindrome_anagram(string& word, const vector<string>& dictionary);

bool anonymous_letter(const string& L, const string& M);
vector<int> intersection_sorted_arrays(vector<int> A, vector<int> B);
vector<int> intersection_unsorted_arrays(vector<int> A, vector<int> B);
vector<int> difference_unsorted_arrays(vector<int> A, vector<int> B);
vector<int> symmetric_difference_sorted_arrays(vector<int> A, vector<int> B);

std::tuple<vector<int>,vector<int>,vector<int> > union_intersection_difference(vector<int>& A, vector<int>& B);

void merge_two_sorted_arrays(int A[], int m, int B[], int n);
void count_occurrences(string& s);

void eliminate_duplicates(vector<int>& v);

bool is_BST_helper(const std::unique_ptr<BSTNode<int> >& T, int lower, int upper);
bool is_BST(const std::unique_ptr<BSTNode<int> >& T);


void hanoi_transfer(int n, array<std::stack<int>, 3>& pegs, int from, int to, int use);
void move_tower_hanoi(int n);

pair<int,int> find_maximum_subarray_sub(const vector<int>& A);

int n_choose_k(int n, int k);
int n_choose_k2(int n, int k);

//int count_combinations(int s, vector<int>& score_ways);
int count_combinations2(int s, vector<int>& score_ways);
int num_paths(int m, int n);
int num_paths2(int m, int n);

int num_paths_with_obstacles(int m, int n, const vector<deque<bool> >& B);

int knapsack(int w, const vector<Item<int> >& items);
int knapsack2(int w, const vector<Item<int> >& items);

vector<Num> generate_smallest(int k);
vector<Num> generate_smallest2(int k);
vector<Num> generate_smallest3(int k);

long long tie_election(const vector<int>& V);
long long tie_election2(const vector<int>& V);

vector<string> word_breaking(const string& s, const vector<string>& dictionary);

double house_majority(const vector<double>& prob, int n);

int max_events(const vector<pair<int,int> >& events);

vector<Interval> insert_interval(const vector<Interval>& A, Interval I);

void selection_sort_list(shared_ptr<ListNode<int> >& L);

vector<int> sunset_view(vector<int> heights);

bool is_feasible(const Coordinate<int>& coord, const vector<vector<int> >& maze);
bool search_maze_helper (const Coordinate<int>& curr, const Coordinate<int>& e, vector<vector<int> >* maze, vector<Coordinate<int> >* path);
vector<Coordinate<int> > search_maze(vector<vector<int> >& maze, const Coordinate<int>& s, const Coordinate<int>& e);

void flip_color_region(vector<vector<unsigned int> >* colors, const Coordinate<unsigned int>& s);
void flip_color_region_dfs(vector<vector<unsigned int> >* colors, const Coordinate<unsigned int>& co);
void print_vv(const vector<vector<unsigned int> >& v);

int merge_count(vector<int>& A, int start, int mid, int end);
int inverted_pairs(vector<int>& A, int start, int end);

pair<double,double> compute_height_diameter(const unique_ptr<TreeVertex<int> >& T);
double diameter(const unique_ptr<TreeVertex<int> >& T);

void combination_helper(int n, int k, int start, vector<vector<int> >* res, vector<int>* ans);
vector<vector<int> > combinations(int n, int k);

int water_tapped(const vector<int>& A);

int fib_1(int n);
int fib_2(int n);
int fib_3(int n);
int fib_4(int n);

unsigned int fact_1(unsigned int n);
unsigned int fact_2(unsigned int n);
unsigned int fact_3(unsigned int n);

template <long long int n>
struct factorial {
  enum { value = n * factorial<n - 1>::value };
};

template <>
struct factorial<0> {
  enum { value = 1 };
};

template <class T>
struct equal_to {
  equal_to(T x) : k(x) {};
  bool operator() (T x) {return x == k;};
private:
  T k;
};

template <class T>
struct less_than {
  less_than(T x) : k(x) {};
  bool operator() (T x) {return x < k;};
private:
  T k;
};

template <class T>
struct greater_than {
  greater_than(T x) : k(x) {};
  bool operator() (T x) {return x > k;};
private:
  T k;
};

template <class T>
struct add_k {
  add_k(T x) : k(x) {};
  T operator() (T x) {return x + k;};
private:
  T k;
};

template <class T>
struct add_k_mod_m {
  add_k_mod_m(T x, T y) : k(x), m(y) {};
  T operator() (T x) {return (x + k) % m; };
private:
  T k;
  T m;
};

class decimal_digit {
public:
  decimal_digit() : n_(0) {};
  decimal_digit(const char c) : n_( isdigit(c) ? c - '0' : c - 'A' + 10 ) {};
  decimal_digit(int n) : n_(n % 10) {};
  operator int () const { return n_; };
private:
  int n_;
};

const decimal_digit carry(const decimal_digit& d1, const decimal_digit& d2, const decimal_digit& c);

template <class BiDirIt, class UnaryPredicate>
BiDirIt my_partition(BiDirIt first, BiDirIt last, UnaryPredicate p) {
  last--;
  while (first != last) {
    if (p(*first))
      first++;
    else
      iter_swap(first, last--);
  }
  return first;
}

template <class ForwardIt, class UnaryPredicate>
int my_count_if(ForwardIt first, ForwardIt last, UnaryPredicate p) {
  int count = 0;
  while (first != last) {
    if (p(*first))
      count++;
    first++;
  }
  return count;
}

template <class ForwardIt, class T>
int my_count(ForwardIt first, ForwardIt last, const T& value) {
  int count = 0;
  while (first != last) {
    if (*first == value)
      count++;
    first++;
  }
  return count;
}

template <class BiDirIt, class UnaryPredicate1, class UnaryPredicate2>
BiDirIt dutch_flag_partition(BiDirIt first, BiDirIt last, UnaryPredicate1 p1, UnaryPredicate2 p2) {
  BiDirIt middle = first;
  last--;
  while (middle != last) {
    if (p1(*middle))
      iter_swap(middle++, first++);
    else if (p2(*middle))
      middle++;
    else
      iter_swap(middle, last--);
  }
  return middle;
}

template <class BiDirIt, class T>
BiDirIt dutch_flag_partition(BiDirIt first, BiDirIt last, const T& value) {
  BiDirIt middle = first;
  last--;
  while (middle != last) {
    if (*middle < value) {
      iter_swap(middle++, first++);
    } else if (*middle == value) {
      middle++;
    } else {
      iter_swap(middle, last--);
    }
  }
  return middle;
}

template <class ForwardIt>
void my_rotate(ForwardIt first, ForwardIt first_n, ForwardIt last)
{
  ForwardIt next = first_n;
  while (first != next) {
    std::iter_swap(first++, next++);
    if (next == last)
      next = first_n;
    else if (first == first_n)
      first_n = next;
  }
}

// Bentley version
template <class BiDirIt>
void my_insertion_sort(BiDirIt first, BiDirIt last)
{
  for (BiDirIt i = first; i != last; ++i) {
    for (BiDirIt j = i; i != first && *(j - 1) > *j; --j) { // why doesn't >= work?
      iter_swap(j - 1, j);
    }
  }
}

class BigInt
{
public:
  BigInt(int capacity) : n_(capacity) {};
  BigInt(const std::vector<decimal_digit>& v) : n_(v) {};
  void print() const { for (auto x : n_) { std::cout << x << ' '; } std::cout << std::endl; };

  const decimal_digit& operator[] (std::size_t i) const { return n_[i]; };
  decimal_digit& operator[] (std::size_t i) { const_cast<decimal_digit&>(static_cast<const BigInt&>(*this)[i]); };

  std::vector<decimal_digit>::const_iterator begin() const { return n_.begin(); };
  std::vector<decimal_digit>::const_iterator end() const { return n_.end(); };

  const BigInt s() const;
  const BigInt a(const BigInt& b) const;

private:
  void increment();
  void add(const BigInt& b);
  std::vector<decimal_digit> n_;
};

const BigInt s(const BigInt& b);
const BigInt add(const BigInt& b1, const BigInt& b2);

template <class T, class ADD, class MULT>
T general_knapsack(const vector<Item<T> >& Items, bool unique, T capacity_in, T capacity_out)
{
  array<vector<T>, 2> table{vector<T>(capacity_in + 1, 0), vector<T>(capacity_in + 1, 0)};
  table[0][0] = MULT::identity;
  for (int i = 0; i < Items.size(); ++i) {
    int r = unique? i&1 : (i+1)&1;
    for (int j = 0; j <= capacity_in; ++j) {
      table[(i+1)&1][j] =
	(j >= Items[i].weight ? AXPY<T,T,ADD,MULT>(Items[i].value) (table[r][j - Items[i].weight], table[i&1][j]) : table[i&1][j]);
    }
  }
  return table[Items.size()&1][capacity_out];
}




#endif
