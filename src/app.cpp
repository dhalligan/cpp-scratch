#include <iostream>
#include <cstdlib>
#include <cctype>
#include <exception>
#include <stdexcept>
#include <memory>
#include <sstream>

#include "app.h"

App::App(int& argc, char** argv)
{
  std::cout << "Creating aapplication..." << std::endl;
  std::cout << "Finished." << std::endl;
}

App::~App()
{
}

int App::exec()
{
  std::cout << "Running application..." << std::endl;
  std::cout << std::endl;

  Rand_int rnd {0, 5};
  vector<int> rolls(6, 0);
  for (int i = 0; i < 200; ++i) {
    rolls[rnd()]++;
  }
  for (int i = 0; i < rolls.size(); ++i) {
    cout << "Rolled " << i + 1 << ": ";
    for (int j = 0; j < rolls[i]; ++j) {
      cout << "*";
    }
    cout << endl;
  }

  vector<int> score_ways {1, 2, 3};
  CountPermutation cp;
  cout << "cp: " << cp.compute(10, score_ways) << endl;

  //  display_image("input/cat_ferret.jpg");

  Matrix m(1, 1, MatType<double>::type);
  m.operator()<double>(0, 0) = 42.42;
  double test = m.operator()<double>(0, 0);
  cout << "test = " << test << endl;

  Matrix n(1, 1, MatType<uint8_t>::type);
  n.operator()<uint8_t>(0, 0) = 42;
  uint8_t test2 = n.operator()<uint8_t>(0, 0);
  cout << "test2 = " << static_cast<int>(test2) << endl;

  StackOneQueue<int> soq;

}

int ssDecodeColID(const std::string& s) {
  return Polynomial<std::string::const_iterator, const int, const letter>(s.begin(), s.end())(26);
}

// std::string convert_base(const std::string& s, const int base1, const int base2)
// {
//   return integer_to_string( string_to_integer(s, base1), base2);
// }

Parity::Parity() {
  unsigned short i = 0;
  do { sixteenBitParityTable[i] = p2(i); i++; } while (i != 65535);
  sixteenBitParityTable[i] = p2(i);

  i = 0;
  do { sixteenBitReverseTable[i] = reverse_short_bits(i); i++; } while (i != 65535);
  sixteenBitReverseTable[i] = reverse_short_bits(i);

  fourBitParityTable = 0x6996;

}

unsigned short
Parity::p1(unsigned long long x) {
  unsigned short res = 0;
  while (x) {
    res ^= (x & 1);
    x >>= 1;
  }
  return res;
}

unsigned short
Parity::p2(unsigned long long x) {
  unsigned short res = 0;
  while (x) {
    res ^= 1;
    x &= (x - 1);
  }
  return res;
}

unsigned short
Parity::p3(unsigned long long x) {
  return
    sixteenBitParityTable[(x >> 48)          ] ^
    sixteenBitParityTable[(x >> 32)  & 0xffff] ^
    sixteenBitParityTable[(x >> 16)  & 0xffff] ^
    sixteenBitParityTable[(x      )  & 0xffff] ;
}

unsigned short
Parity::p4(unsigned long long x) {
  x ^= (x >> 32);
  x ^= (x >> 16);
  x ^= (x >> 8);
  x ^= (x >> 4);
  return (fourBitParityTable >> x) & 1;
}

unsigned short
Parity::reverse_short_bits(unsigned short x) {
  for (int i = 0; i != 8; ++i) {
    int j = 15 - i;
    x = swap_bits( x, i, j );
  }
  return x;
}

unsigned long long
Parity::reverse_bits(unsigned long long x) {
  return
    (unsigned long long) (sixteenBitReverseTable[(x >> 48)          ])        |
    (unsigned long long) (sixteenBitReverseTable[(x >> 32)  & 0xffff]) << 16  |
    (unsigned long long) (sixteenBitReverseTable[(x >> 16)  & 0xffff]) << 32  |
    (unsigned long long) (sixteenBitReverseTable[(x      )  & 0xffff]) << 48  ;
}

long long
Parity::swap_bits(long long x, int i, int j)
{
  if (((x >> i) & 1) != ((x >> j) & 1)) {
    x ^= ((1LL << i) | (1LL << j));
  }
  return x;
}

unsigned long long closest_int_same_bits(unsigned long long x)
{
  for (int i = 0; i != 63; ++i) {
    if (((x >> i) & 1) ^ ((x >> (i+1)) & 1)) {
      x ^= ((1L << i) | (1L << (i+1)));
      return x;
    }
  }
  throw std::invalid_argument("all bits are identical!");
}

unsigned long long next_int_same_bits(unsigned long long n)
{
  int c = n, t0 = 0, t1 = 0;
  while (((c & 1) == 0) && (c != 0)) { t0++; c >>= 1; }  // count trailing zeros
  while ((c & 1) == 1) { t1++; c >>= 1; }                // count ones

  if ((t0 + t1 == 63)) return 0;
  int p = t0 + t1;                                       // position of first non-trailing zero

  n ^= (1 << p);                                         // flip first non-trailing zero
  n &= ~((1 << p) - 1);                                  // clear bits after it
  n |= (1 << (t1 - 1)) - 1;                              // put the rest of the ones as far right as possible

  return n;
}

unsigned long long previous_int_same_bits(unsigned long long n)
{
  int c = n, t0 = 0, t1 = 0;
  if (c == 0) return -1;

  while ((c & 1) == 1) { t1++; c >>= 1; }                // count trailing ones
  while (((c & 1) == 0) && (c != 0)) { t0++; c >>= 1; }  // count zeros

  int p = t1 + t0;                                       // position of first non-trailing one

  n ^= (1 << p);                                         // flip first non-trailing one
  n &= ~((1 << p) - 1);                                  // clear bits after it
  n |= (((1 << (t1 + 1)) - 1) << (t0 - 1));              // put the rest of the ones as far left as possible

  return n;
}

void print_fraction_binary(double x)
{
  string result;
  int size = 0;
  double frac = 0.5;
  result.append("0.");
  while (x != 0 && size != 64) {
    if (x >= frac) {
      result.push_back('1');
      x -= frac;
    } else {
      result.push_back('0');
    }
    frac /= 2;
    size++;
  }
  std::cout << result << std::endl;
}

double pow(double x, int y)
{
  double res = 1.0;
  long long power = y;

  if (y < 0) {
    power = -power;
    x = 1.0 / x;
  }

  while (power) {
    if (power & 1) {
      res *= x;
    }
    x *= x;
    power >> 1;
  }
  return res;
}

void BigInt::increment()
{
  auto it = n_.begin();
  while ((it != n_.end()) && ((*it = *it + 1) == 0)) { it++; }
  if (it == n_.end()) { n_.push_back(1); }
}

const BigInt BigInt::s() const
{
  BigInt result(*this);
  result.increment();
  return result;
}

const BigInt s(const BigInt& b)
{
  return b.s();
}

void BigInt::add(const BigInt& b)
{
  auto i = n_.begin();
  auto j = b.begin();

  decimal_digit c = 0;
  decimal_digit d = 0;
  while (i != n_.end() && j != b.end()) {
    d = *i + *j + c;
    c = carry(*i, *j, c);
    *i = d;
    i++; j++;
  }
  if (i == n_.end()) {
    while (j != b.end()) {
      d = *j + c;
      c = carry(0, *j, c);
      n_.push_back(d);
      j++;
    }
    if (c != 0) n_.push_back(c);
  } else {
    *i = *i + c;
  }

}

const BigInt BigInt::a(const BigInt& b) const
{
  BigInt result(*this);
  result.add(b);
  return result;
}

const decimal_digit carry(const decimal_digit& d1, const decimal_digit& d2, const decimal_digit& c)
{
  return (d1 + d2 + c) / 10;
}

int smallest_missing_positive(std::vector<int>& v)
{
  using std::swap;
  int i = 0;
  while (i < v.size()) {
    if ((0 < v[i] && v[i] <= v.size()) && // v[i] is in the range [1, n]
	v[i] != i + 1 &&                  // v[i] is not locked in its final place
	v[i] != v[v[i]-1])                // not swapping equal elements
      swap(v[i], v[v[i]-1]);
    else {
      i++;
    }
  }
  for (int i = 0; i < v.size(); i++) {
    if (v[i] != i+1)
      return i+1;
  }
  return v.size() + 1;

}

int max_forward_diff(const std::vector<int>& v)
{
  int min = std::numeric_limits<int>::max();
  int max_diff = 0;

  for (auto i : v) {
    max_diff = std::max( max_diff, i - min);
    min = std::min(min, i);
  }
  return max_diff;
}

int max_forward_diff_2(const std::vector<int>& v)
{
  int min = std::numeric_limits<int>::max(), max_diff = 0;

  std::vector<int> max_diffs;
  for (auto i = v.begin(); i != v.end(); i++) {
    max_diff = std::max( max_diff, *i - min);
    min = std::min(min, *i);
    max_diffs.push_back(max_diff);
  }

  int max = 0, min_diff = std::numeric_limits<int>::max();
  int max_sum = 0;

  auto i = v.rbegin();
  auto j = max_diffs.rbegin();
  for ( ; i != v.rend() && j != max_diffs.rend(); i++, j++){
    min_diff = std::min(min_diff, *i - max);
    max = std::max(max, *i);
    max_sum = std::max(max_sum, -min_diff + *j);
  }
  return max_sum;

}

void remove_replace(std::string& s, char remove, char replace, char with)
{
  my_replace(s.begin(), s.end(), replace, with);
  s.erase(my_remove(s.begin(), s.end(), remove), s.end());
}

std::string reverse_sentence(const std::string& s)
{
  std::string result(s);
  my_reverse(result.begin(), result.end());
  auto i = result.begin();
  auto j = result.begin();
  while (i != result.end() && j != result.end()) {
    j = my_find_if(i, result.end(), isspace);
    my_reverse(i, j);
    i = my_find_if_not(j, result.end(), isspace);
  }

  return result;
}

std::vector<std::string> tokenize_sentence(const std::string& s)
{
  std::string t;
  std::vector<std::string> result;
  auto i = s.begin();
  auto j = s.begin();
  while (i != s.end() && j != s.end()) {
    j = my_find_if(i, s.end(), isspace);
    result.push_back(std::string(i, j));
    i = my_find_if_not(j, s.end(), isspace);
  }
  return result;
}

shared_ptr<ListNode<int> > reverse_sublist(const shared_ptr<ListNode<int> >& L, int s, int f)
{
  shared_ptr<ListNode<int> > s_ptr = L, prev_s_ptr = nullptr;
  size_t i = 1;
  while (i < s) {
    prev_s_ptr = s_ptr;
    s_ptr = s_ptr->next;
    i++;
  }

  if (prev_s_ptr)
    prev_s_ptr->next = nullptr;

  shared_ptr<ListNode<int> > curr = s_ptr;
  shared_ptr<ListNode<int> > prev = nullptr;
  shared_ptr<ListNode<int> > f_ptr, next_f_ptr;

  while (i < f) {
    f_ptr = curr->next;
    next_f_ptr = f_ptr->next;
    curr->next = prev;
    prev = curr;
    curr = f_ptr;
    i++;
  }
  f_ptr->next = prev;
  s_ptr->next = next_f_ptr;

  if (prev_s_ptr) {
    prev_s_ptr->next = f_ptr;
    return L;
  } else {
    return f_ptr;
  }

}

// buggy!

// shared_ptr<ListNode<int> > find_cycle(shared_ptr<ListNode<int> > L)
// {
//   shared_ptr<ListNode<int> > slow = L, fast = L;
//   while (slow && slow->next && fast && fast->next && fast->next->next) {
//     // Detect a cycle
//     if (slow == fast) {
//       // There is a cycle
//       // Compute cycle length
//       size_t length = 0;
//       do {fast = fast->next; length++;} while (slow != fast);
//       // Compute beginning of cycle
//       slow = L; fast = L;
//       do {fast = fast->next;} while (--length);
//       do {fast = fast->next; slow = slow->next;} while (slow != fast);
//       return fast;
//     }
//   }
//   // There is no cycle
//   return nullptr;
// }

void selection_sort_list(shared_ptr<ListNode<int> >& L)
{
  if (!(L->next)) return;

  for (auto i = L; i != nullptr; i = i->next) {
    auto min = i;
    for (auto j = i; j != nullptr; j = j->next) {
      min = (j->data < min->data) ? j : min;
    }
    std::swap(i->data, min->data); // switch pointers not data
  }
}

int eval(const std::string& s)
{
  std::stack<int> eval_stack;
  std::stringstream ss(s);

   std::string symbol;
   while (getline(ss, symbol, ',')) {
     if ((symbol == "+") || (symbol == "-") || (symbol == "*") || (symbol == "/")) {
       // Operator
       int y = eval_stack.top();
       eval_stack.pop();
       int x = eval_stack.top();
       eval_stack.pop();
       int result = 0;
       switch (symbol.front()) {
       case '+' :
	 result = x + y;
	 break;
       case '-' :
	 result = x - y;
	 break;
       case '*' :
	 result = x * y;
	 break;
       case '/' :
	 result = x / y;
	 break;
       default :
	 result = 0;
       }
       eval_stack.emplace(result);
     } else {
       // Number
       eval_stack.emplace(std::stoi(symbol));
     }
   }
   return eval_stack.top();
}

bool pbb(const std::string& s)
{
  std::stack<char> stack;

  for (auto c : s) {
    if ((c == '(') || (c == '{') || (c == '[')) {
      stack.emplace(c);
    } else {
      if (stack.empty())
	return false;
      char top = stack.top();
      if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '['))
	return false;
      else
	stack.pop();
    }
  }
  return stack.empty();
}

int match_length(const std::string& s)
{
  std::stack<int> stack;
  size_t max_len = 0, last_end = 0;

  for (size_t i = 0; i != s.size(); ++i) {
    if (s[i] == '(') {
      stack.emplace(i);
    } else {
      if (stack.empty()) {
	// Matching failed. Move past this prefix.
	last_end = i + 1;
      } else {
	// Natched a paren. Compute distance to next unmatched paren.
	stack.pop();
	size_t start = stack.empty() ? last_end - 1 : stack.top();
	max_len = std::max(max_len, i - start);
      }
    }
  }
  return max_len;
}

void insert(int e, std::stack<int>& s) {
  if (s.empty() || s.top() <= e) {
    s.push(e);
  } else {
    int t = s.top();
    s.pop();
    insert(e, s);
    s.push(t);
  }
}

void sort(std::stack<int>& s)
{
  if (!s.empty()) {
    int e = s.top();
    s.pop();
    sort(s);
    insert(e, s);
  }
}

vector<int> sunset_view(vector<int> heights)
{
  std::stack<int> stack;
  for (int h : heights) {
    while (!stack.empty() && h > stack.top()) {
      stack.pop();
    }
    stack.emplace(h);
  }
  vector<int> result;
  while (!stack.empty()) {
    result.emplace_back(stack.top());
    stack.pop();
  }
  reverse(result.begin(), result.end());
  return result;
}

int height(const unique_ptr<BinaryTreeNode<int> >& T)
{
  if (!T) return -1;

  int lheight = height(T->left);
  if (lheight == -2) return -2;
  int rheight = height(T->right);
  if (rheight == -2) return -2;

  if (std::abs(lheight - rheight) > 1) return -2;

  return (std::max(lheight, rheight) + 1);
}

bool balanced(const unique_ptr<BinaryTreeNode<int> >& T)
{
  return (height(T) != -2);
}

std::pair<BinaryTreeNode<int>*,int> nodes(const unique_ptr<BinaryTreeNode<int> >& T, int k)
{
  if (!T) return {nullptr, 0};

  auto lnodes = nodes(T->left, k);
  if (lnodes.first) return lnodes;
  auto rnodes = nodes(T->right, k);
  if (rnodes.first) return rnodes;

  int num_nodes = lnodes.second + rnodes.second + 1;
  if (std::abs(lnodes.second - rnodes.second) > k) return {T.get(), num_nodes};

  return {nullptr, num_nodes};
}

BinaryTreeNode<int>* find_non_k_balanced_node(const unique_ptr<BinaryTreeNode<int> >& T, int k)
{
  return nodes(T, k).first;
}

int balanced_height(const unique_ptr<BinaryTreeNode<int> >& T)
{
  if (!T) return -1;

  auto lheight = balanced_height(T->left);
  if (lheight == -2) return -2;
  auto rheight = balanced_height(T->right);
  if (rheight == -2) return -2;

  if (std::abs(lheight - rheight) > 1) return -2;

  return std::max(lheight, rheight) + 1;
}

bool is_balanced(const unique_ptr<BinaryTreeNode<int> >& T)
{
  return balanced_height(T) != -2;
}

bool symmetric_match(const unique_ptr<BinaryTreeNode<int> >& L, const unique_ptr<BinaryTreeNode<int> >& R)
{
  if (!L && !R) return true;

  return
    (L && R) &&
    (L->data == R->data) &&
    symmetric_match(L->left, R->right) &&
    symmetric_match(L->right, R->left);
}

bool symmetric(const unique_ptr<BinaryTreeNode<int> >& T)
{
  return symmetric_match(T->left, T->right);
}

BinaryTreeNode<int>*
lca(const unique_ptr<BinaryTreeNode<int> >& T, const unique_ptr<BinaryTreeNode<int> >& A, const unique_ptr<BinaryTreeNode<int> >& B)
{
  if (!T) return nullptr;

  // This is A or B
  if (T == A || T == B) return T.get();

  auto *left = lca(T->left, A, B);
  auto *right = lca(T->right, A, B);

  // A, B in different subtrees; this is the lca
  if (left && right) return T.get();

  // A, B in same subtree; propagate lca result
  return left? left : right;
}

int
depth(const BinaryTreeNode2<int>* T)
{
  int d = 0;
  while (T) { T = T->parent; d++; };
  return d;
}

BinaryTreeNode2<int>*
lca2(const unique_ptr<BinaryTreeNode2<int> >& T, const unique_ptr<BinaryTreeNode2<int> >& A, const unique_ptr<BinaryTreeNode2<int> >& B)
{
  auto *i = A.get(), *j = B.get();
  int depth_i = depth(i);
  int depth_j = depth(j);
  if (depth_j > depth_i) std::swap(i, j);

  int depth_diff = std::abs(depth_i - depth_j);
  while (depth_diff--) { i = i->parent; };

  while (i != j) { i = i->parent; j = j->parent; };

  return i;
}

int inorder_traversal_1(const unique_ptr<BinaryTreeNode<int> >& T, int parent_num)
{
  if (!T) return 0;
  int node_num = parent_num << 1 + T->data;

  // This is a leaf, return the number at the node
  if (!T->left && !T->right) return node_num;

  // This is an interior node, add the left and right sums
  return inorder_traversal_1(T->left, node_num) + inorder_traversal_1(T->right, node_num);
}

int sum_root_to_leaf_paths(const unique_ptr<BinaryTreeNode<int> >& T)
{
  return inorder_traversal_1(T, 0);
}

bool inorder_traversal_2(const unique_ptr<BinaryTreeNode<int> >& T, int parent_num, int target)
{
  if (!T) return false;
  int node_num = parent_num + T->data;

  // This is a leaf, check the number at the node
  if (!T->left && !T->right) return node_num == target;

  // This is an interior node, check the left then right branches
  return inorder_traversal_2(T->left, node_num, target) || inorder_traversal_2(T->right, node_num, target);
}

int find_root_to_leaf_path(const unique_ptr<BinaryTreeNode<int> >& T, int target)
{
  return inorder_traversal_2(T, 0, target);
}

void inorder_traversal(const unique_ptr<BinaryTreeNode2<int> >& T)
{
  if (!T) return;

  BinaryTreeNode2<int> *prev = nullptr, *curr = T.get(), *next;

  while (curr) {
    if (!prev || curr == prev->left.get() || curr == prev->right.get()) {
      // Coming from parent node
      if (curr->left) {
	next = curr->left.get();
      } else {
	std::cout << curr->data << std::endl;
	next = (curr->right ? curr->right.get() : curr->parent);
      }
    } else if (curr->left.get() == prev) {
      // Coming back from left child
      std::cout << curr->data << std::endl;
      next = (curr->right ? curr->right.get() : curr->parent);
    } else {
      // Coming back from right child
      next = curr->parent;
    }
    prev = curr;
    curr = next;
  }
}

// errors! ///

// vector<int> inorder_traversal(const unique_ptr<BinaryTreeNode<int> >& T)
// {
//   stack<BinaryTreeNode<int>* > stack;
//   vector<int> result;
//   auto curr = T.get();
//   while (!stack.empty() && curr) {
//     if (curr) {
//       stack.emplace(curr);
//       curr = curr->left.get();
//     } else {
//       result.emplace_back(curr->data);
//       stack.pop();
//       curr = curr->right.get();
//     }
//   }
//   return result;
// }

vector<int> preorder_traversal(const unique_ptr<BinaryTreeNode<int> >& T)
{
  stack<BinaryTreeNode<int>* > stack;
  vector<int> result;
  stack.emplace(T.get());
  while (!stack.empty()) {
    auto curr = stack.top();
    stack.pop();
    result.emplace_back(curr->data);
    if (curr->right) stack.emplace(curr->right.get());
    if (curr->left) stack.emplace(curr->left.get());
  }
  return result;
}

vector<int> reverse_preorder_traversal(const unique_ptr<BinaryTreeNode<int> >& T)
{
  stack<BinaryTreeNode<int>* > stack;
  vector<int> result;
  stack.emplace(T.get());
  while (!stack.empty()) {
    auto curr = stack.top();
    stack.pop();
    result.emplace_back(curr->data);
    if (curr->left) stack.emplace(curr->left.get());
    if (curr->right) stack.emplace(curr->right.get());
  }
  return result;
}

vector<int> postorder_traversal(const unique_ptr<BinaryTreeNode<int> >& T)
{
  vector<int> result = reverse_preorder_traversal(T);
  reverse(result.begin(), result.end());
  return result;
}

BinaryTreeNode3<int>* inorder_kth_node(const unique_ptr<BinaryTreeNode3<int> >& T, int k)
{
  auto *n = T.get();
  while (n) {
    int left_size = T->left->size;
    if (left_size < k - 1) {
      k -= (left_size + 1);
      n = n->right.get();
    } else if (left_size == k - 1) {
      return n;
    } else {
      n = n->left.get();
    }
  }
  throw std::length_error("no kth node in tree");
}

struct Compare {
  bool operator() (const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) {
    return lhs.first > rhs.first;
  }
};

vector<int> merge_arrays(const vector<vector<int> >& S)
{
  std::priority_queue<std::pair<int, int>, vector<std::pair<int, int> >, Compare> min_heap;
  vector<int> S_idx(S.size(), 0);

  for (int i = 0; i != S.size(); ++i) {
    if (S[i].size() > 0) {
      min_heap.emplace(S[i][0], i);
      S_idx[i] = 1;
    }
  }

  vector<int> result;
  while (!min_heap.empty()) {
    pair<int, int> p = min_heap.top();
    result.emplace_back(p.first);
    if (S_idx[p.second] < S[p.second].size()) {
      min_heap.emplace(S[p.second][(S_idx[p.second])++], p.second);
    }
    min_heap.pop();
  }
  return result;
}

vector<int> kid_sort(const vector<int>& v)
{
  vector<vector<int> > s;
  bool increasing = true;
  int start_idx = 0;

  for (int i = 0; i != v.size(); ++i) {
    if (increasing && v[i] <= v[i-1] ||
	!increasing && v[i] > v[i-1]) {
      if (increasing) {
	s.emplace_back(v.cbegin()+start_idx, v.cbegin()+i);
      } else {
	s.emplace_back(v.crbegin()+v.size()-i, v.crbegin()+v.size()-start_idx);
      }
      start_idx = i;
      increasing = !increasing;
    }
  }

  if (start_idx < v.size()) {
    if (increasing) {
      s.emplace_back(v.cbegin()+start_idx, v.cend());
    } else {
      s.emplace_back(v.crbegin(), v.crbegin()+v.size()-start_idx);
    }
  }
  return merge_arrays(s);
}

vector<int> kaway_sort(const vector<int>& v, int k)
{
  vector<int> result;
  std::priority_queue<int, vector<int>, std::greater<int> > min_heap;

  for (int i = 0 ; i != v.size(); ++i) {
    if (min_heap.size() == k) {
      min_heap.emplace(v[i]);
      result.emplace_back(min_heap.top());
      min_heap.pop();
    } else {
      min_heap.emplace(v[i]);
    }
  }

  while (!min_heap.empty()) {
    result.emplace_back(min_heap.top());
    min_heap.pop();
  }

  return result;
}

vector<Star> k_closest_stars(int k, std::istringstream *sin)
{
  std::priority_queue<Star, vector<Star> > max_heap;
  std::string line;

  while (getline(*sin, line)) {
    stringstream ss(line);
    string buf;
    getline(ss, buf, ',');
    int id = stoi(buf);
    array<double, 3> data;
    for (int i = 0; i != 3; ++i) {
      getline(ss, buf, ',');
      data[i] = stod(buf);
    }
    Star star{id, data[0], data[1], data[2]};

    if (max_heap.size() == k) {
      Star far_star = max_heap.top();
      if (star < far_star) {
	max_heap.pop();
	max_heap.emplace(star);
      }
    } else {
      max_heap.emplace(star);
    }
  }

  vector<Star> result;
  while (!max_heap.empty()) {
    result.emplace_back(max_heap.top());
    max_heap.pop();
  }

  return result;
}

void online_median(std::istream& in)
{
  // Min heap to store the higher elements
  std::priority_queue<int, vector<int>, greater<int> > H;
  // Max heap to store the lower elements
  std::priority_queue<int, vector<int>, less<int> > L;

  int x;
  while (in >> x) {

    // Push integer into higher or lower heap
    if (!L.empty() && x > L.top()) {
      H.push(x);
    } else {
      L.push(x);
    }

    // Balance heap sizes if necessary
    if (H.size() > L.size() + 1) {
      L.push(H.top());
      H.pop();
    } else if (L.size() > H.size() + 1) {
      H.push(L.top());
      L.pop();
    }

    if (L.size() == H.size()) {
      std::cout << "online median: " << 0.5 * (L.top() + H.top()) << std::endl;
    } else {
      std::cout << "online median: " << (H.size() > L.size() ? H.top() : L.top()) << std::endl;
    }
  }
}

int k_largest(std::priority_queue<int, vector<int>, less<int> >& mh, int k)
{
  int count = 0;
  while (!mh.empty() && count != k) {
    std::cout << "max: " << mh.top() << std::endl;
    mh.pop();
    count++;
  }
  return 0;
}

struct Compare2 {
  bool operator() (const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) {
    return lhs.second < rhs.second;
  }
};

vector<int> k_largest_in_binary_heap(const vector<int>& A, int k)
{
  std::priority_queue<pair<int,int>, vector<pair<int, int> >, Compare2> max_heap;

  max_heap.push({0, A[0]});
  vector<int> result;
  for (int i = 0; i != k; ++i) {
    int idx = max_heap.top().first;
    result.push_back(max_heap.top().second);
    max_heap.pop();

    int idx_l = 2*idx + 1;
    if (idx_l < A.size()) {
      max_heap.push({idx_l, A[idx_l]});
    }
    int idx_r = 2*idx + 2;
    if (idx_r < A.size()) {
      max_heap.push({idx_r, A[idx_r]});
    }
  }
  return result;
}

// int binary_search(int k, const vector<int>& A)
// {
//   int L = 0, U = A.size()-1;
//   int R = -1;
//   while (L <= U) {
//     int M = (L < 0) == (U < 0) ? L + (U - L) / 2 : (L + U) / 2;
//     if (A[M] < k) {
//       L = M + 1;
//     } else if (A[M] == k) {
//       R = M; U = M - 1;
//     } else {
//       U = M - 1;
//     }
//   }
//   return R;
// }

int binary_search_greater(int k, const vector<int>& A)
{
  int L = 0, U = A.size()-1;
  int R = -1;
  while (L <= U) {
    int M = (L < 0) == (U < 0) ? L + (U - L) / 2 : (L + U) / 2;
    if (A[M] <= k) {
      L = M + 1;
    } else {
      R = M; U = M - 1;
    }
  }
  return R;
}

int binary_search_fixed_point(const vector<int>& A)
{
  int L = 0, U = A.size() - 1;
  int R = -1;
  while (L <= U) {
    int M = ((L < 0) == (U < 0) ? L + (U - L) / 2 : (L + U) / 2);
    if (A[M] - M < 0 )
      L = M + 1;
    else if (A[M] - M == 0) {
      R = M; U = M - 1;
    } else
      U = M - 1;
  }
  return R;
}

// Min value of circular array *assuming no repeats*
// int binary_search_min_circular(const vector<int>& A)
// {
//   int L = 0, U = A.size()-1;
//   while (L < U) {
//     int M = (L < 0) == (U < 0) ? L + (U - L) / 2 : (L + U) / 2;
//     if (A[M] > A[U]) {
//       L = M + 1;
//     } else {
//       U = M;
//     }
//   }
//   return L;
// }

// int binary_search_circular(int k, const vector<int>& A)
// {
//   int L = 0, R = A.size() - 1;
//   int M = binary_search_min_circular(A);
//   if (k > A[R])
//     return binary_search(k, vector<int>(A.cbegin(), A.cbegin() + M));
//   else
//     return M + binary_search(k, vector<int>(A.cbegin() + M, A.cend()));
// }

void find_anagrams(const vector<string>& dictionary)
{
  std::unordered_map<string, vector<string> > hash;
  for (const string& s : dictionary) {
    string sorted(s);
    std::sort(sorted.begin(), sorted.end());
    hash[sorted].emplace_back(s);
  }

  for (const pair<string, vector<string> >& p : hash) {
    if (p.second.size() >= 2) {
      for (auto s : p.second) {
	std::cout << s << " " << std::endl;
      }
      std::cout << std::endl;
    }
  }
}

bool anonymous_letter(const string& L, const string& M)
{
  std::unordered_map<char,int> hash;
  for_each (L.begin(), L.end(), [&hash] (const char& c) {hash[c]++; });

  for (const char& c : M) {
    auto it = hash.find(c);
    if (it != hash.cend()) {
      if (--it->second == 0) {
	hash.erase(it);
	if (hash.empty() == true) {
	  return true;
	}
      }
    }

  }

  return hash.empty();
}

vector<int> intersection_sorted_arrays(vector<int> A, vector<int> B)
{
  int i = 0, j = 0;
  vector<int> result;
  while (i != A.size() && j != B.size()) {
    if (A[i] == B[j] && (i == 0 || A[i] != A[i-1])) {
      result.emplace_back(A[i]);
      i++; j++;
    } else if (A[i] < B[j]) {
      i++;
    } else {
      j++;
    }
  }
  return result;
}

vector<int> intersection_sorted_arrays2(vector<int> A, vector<int> B)
{
  vector<int> result;
  for (int i = 0; i != A.size(); ++i)
    if ((i == 0 || A[i] != A[i-1]) && binary_search(B.cbegin(), B.cend(), A[i]))  {
      result.emplace_back(A[i]);
    }
  return result;
}

vector<int> intersection_unsorted_arrays(vector<int> A, vector<int> B)
{
  std::unordered_map<int,int> hash;
  for_each (A.cbegin(), A.cend(), [&hash] (const int& i) { hash[i]++; });

  vector<int> result;
  for (const int& i : B) {
    auto it = hash.find(i);
    if (it != hash.cend()) {
      result.emplace_back(i);
      hash.erase(it);
    }
  }

  return result;
}

std::tuple<vector<int>,vector<int>,vector<int> > union_intersection_difference(vector<int>& A, vector<int>& B)
{
  std::unordered_map<int,int> u_hash, i_hash;
  for_each (A.cbegin(), A.cend(), [&u_hash] (const int& i) { u_hash[i]++; });
  for_each (B.cbegin(), B.cend(), [&u_hash, &i_hash] (const int& i) { if (u_hash.find(i) != u_hash.cend()) i_hash[i]++; } );
  for_each (B.cbegin(), B.cend(), [&u_hash] (const int& i) { u_hash[i]++; });

  std::unordered_map<int,int> d_hash(u_hash);
  for_each (i_hash.cbegin(), i_hash.cend(), [&i_hash, &d_hash] (std::pair<int,int> p)
	    { auto it = d_hash.find(p.first);
	      if (it != d_hash.cend())
		d_hash.erase(it); }
	    );

  vector<int> u_result, i_result, d_result;
  for_each (u_hash.cbegin(), u_hash.cend(), [&u_result] (std::pair<int,int> p) {u_result.push_back(p.first);} );
  for_each (i_hash.cbegin(), i_hash.cend(), [&i_result] (std::pair<int,int> p) {i_result.push_back(p.first);} );
  for_each (d_hash.cbegin(), d_hash.cend(), [&d_result] (std::pair<int,int> p) {d_result.push_back(p.first);} );

  return std::tuple<vector<int>,vector<int>,vector<int> >(u_result, i_result, d_result);
}

void count_occurrences(string& s)
{
  sort( s.begin(), s.end() );
  int count = 1;
  for (int i = 1; i != s.size(); ++i) {
    if (s[i] == s[i-1]) {
      count++;
    } else {
      std::cout << s[i-1] << ": " << count << std::endl;
      count = 1;
    }
  }
  std::cout << s.back() << ": " << count << std::endl;
}

void eliminate_duplicates(vector<int>& v)
{
  sort( v.begin(), v.end() );
  v.erase( unique(v.begin(), v.end()), v.end() );
}

int max_events(const vector<pair<int,int> >& events)
{
  vector<Event_Point> points;
  for (auto e : events) { points.emplace_back(Event_Point{e.first, true}); points.emplace_back(Event_Point{e.second, false}); }

  sort(points.begin(), points.end());

  int same = 0, max_same = 0;
  for (auto e : points) {
    if (e.is_start) {
      max_same = std::max(max_same, ++same);
    } else {
      --same;
    }
  }
  return max_same;
}

vector<Interval> insert_interval(const vector<Interval>& A, Interval I)
{
  vector<Interval> result;
  int i = 0;
  while (i != A.size() && I.left > A[i].right) {
    result.emplace_back(A[i++]);
  }

  while (i != A.size() && I.right >= A[i].left) {
    I = {std::min(A[i].left, I.left), std::max(A[i].right, I.right)};
    i++;
  }
  result.emplace_back(I);

  result.insert(result.end(), A.begin() + i, A.end());
  return result;
}

vector<Interval2> union_intervals(vector<Interval2> A)
{
  if (A.empty()) return {};

  sort(A.begin(), A.end());
  vector<Interval2> result;
  Interval2 curr = A[0];
  int i = 0;
  while (i != A.size()) {
    if (curr.right.val > A[i].left.val || (curr.right.val == A[i].left.val && (curr.right.closed || A[i].left.closed))) {
      if (curr.right.val < A[i].right.val || (curr.right.val == A[i].right.val && A[i].right.closed)) {
	curr.right = A[i].right;
      } else {
	result.emplace_back(curr);
	curr = A[i];
      }
    }
    i++;
  }
  result.emplace_back(curr);
  return result;
}

bool is_BST_helper(const std::unique_ptr<BSTNode<int> >& T, int lower, int upper)
{
  if (!T) return true;

  if (lower > T->data || T->data > upper)
    return false;
  else
    return is_BST_helper(T->left, lower, T->data) && is_BST_helper(T->right, T->data, upper);
}

bool is_BST(const std::unique_ptr<BSTNode<int> >& T)
{
  return is_BST_helper(T, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
}

BSTNode<int>* find_equal_k(const std::unique_ptr<BSTNode<int> >& T, int k)
{
  if (!T) return nullptr;

  if (T->data == k) {
    return T.get();
  } else {
    return find_equal_k(T->data > k ? T->left : T->right, k);
  }
}

BSTNode<int>* find_equal_k2(const std::unique_ptr<BSTNode<int> >& T, int k)
{
  BSTNode<int>* curr = T.get();
  while (curr) {
    if (curr->data == k) {
      return curr;
    } else {
      curr = (curr->data > k ? curr->left.get() : curr->right.get());
    }
  }
  return curr;
}

BSTNode<int>* find_first_equal_k(const std::unique_ptr<BSTNode<int> >& T, int k)
{
  if (!T) return nullptr;

  if (T->data == k) {
    auto* N = find_first_equal_k(T->left, k);
    return N ? N : T.get();
  } else {
    return find_first_equal_k(T->data > k ? T->left : T->right, k);
  }
}

BSTNode<int>* find_first_equal_k2(const std::unique_ptr<BSTNode<int> >& T, int k)
{
  BSTNode<int> *first = nullptr, *curr = T.get();
  while (curr) {
    if (curr->data == k) {
      first = curr;
      curr = curr->left.get();
    } else {
      curr = (curr->data > k ? curr->left.get() : curr->right.get());
    }
  }
  return first;
}

BSTNode<int>* find_first_greater_k(const std::unique_ptr<BSTNode<int> >& T, int k)
{
  BSTNode<int> *first = nullptr, *curr = T.get();
  bool found_k;
  while (curr) {
    if (curr->data == k) {
      found_k = true;
      curr = curr->right.get();
    } else if (curr->data > k) {
      first = curr;
      curr = curr->left.get();
    } else {
      curr = curr->right.get();
    }
  }
  return found_k ? first : nullptr;
}

void find_k_largest_in_BST_helper(const std::unique_ptr<BSTNode<int> >& T, int k, vector<int>* k_elements)
{
  if (k_elements->size() < k) {
    find_k_largest_in_BST_helper(T->right, k, k_elements);
    if (k_elements->size() < k) {
      k_elements->emplace_back(T->data);
      find_k_largest_in_BST_helper(T->left, k, k_elements);
    }
  }
}

vector<int> find_k_largest_in_BST(const std::unique_ptr<BSTNode<int> >& T, int k, vector<int>* k_elements)
{
  vector<int> k_largest(k);
  find_k_largest_in_BST_helper(T, k, &k_largest);
  return k_largest;
}

void find_k_smallest_in_BST_helper(const std::unique_ptr<BSTNode<int> >& T, int k, vector<int>* k_elements)
{
  if (k_elements->size() < k) {
    find_k_smallest_in_BST_helper(T->left, k, k_elements);
    if (k_elements->size() < k) {
      k_elements->emplace_back(T->data);
      find_k_smallest_in_BST_helper(T->right, k, k_elements);
    }
  }
}

vector<int> find_k_smallest_in_BST(const std::unique_ptr<BSTNode<int> >& T, int k, vector<int>* k_elements)
{
  vector<int> k_smallest(k);
  find_k_smallest_in_BST_helper(T, k, &k_smallest);
  return k_smallest;
}

BSTNode<int>* find_LCA(const std::unique_ptr<BSTNode<int> >& T,
		       const std::unique_ptr<BSTNode<int> >& S,
		       const std::unique_ptr<BSTNode<int> >& B)
{
  auto* curr = T.get();
  int s = S->data, b = B->data;
  while (curr) {
    if (curr->data > b)
      curr = curr->left.get();
    else if (curr->data < s)
      curr = curr->right.get();
    else
      return curr;
  }
}

void hanoi_transfer(int n, array<std::stack<int>, 3>& pegs, int from, int to, int use)
{
  if (n != 0) {
    hanoi_transfer(n-1, pegs, from, use, to);
    pegs[to].push(pegs[from].top());
    pegs[from].pop();
    std::cout << "Move from peg " << from << " to peg " << to << std::endl;
    hanoi_transfer(n-1, pegs, use, to, from);
  }
}

void move_tower_hanoi(int n)
{
  array<std::stack<int>, 3> pegs;
  for (int i = n; i != 0; --i) { pegs[0].push(i); }
  hanoi_transfer(n, pegs, 0, 1, 2);
}

vector<std::unique_ptr<BinaryTreeNode<int> > > generate_all_binary_trees_helper(int start, int end)
{
  vector<std::unique_ptr<BinaryTreeNode<int> > > result;
  if (start > end) {
    result.emplace_back(nullptr);
    return result;
  }

  for (int i = start; i <= end; ++i) {
    auto left_result = generate_all_binary_trees_helper(start, i - 1);
    auto right_result = generate_all_binary_trees_helper(i + 1, end);
    for (auto& left : left_result) {
      for (auto& right : right_result) {
	result.emplace_back(new BinaryTreeNode<int>{i, std::move(left), std::move(right)});
      }
    }
  }
  return result;
}

pair<int,int> find_maximum_subarray_sub(const vector<int>& A)
{
  pair<int,int> range(0, 0);
  int min_idx = -1, sum = 0, min_sum = 0, max_sum = 0;

  for (int i = 0; i != A.size(); ++i) {
    sum += A[i];
    if (sum < min_sum) {
      min_sum = sum; min_idx = i;
    }
    if (sum - min_sum > max_sum) {
      max_sum = sum - min_sum; range = {min_idx, i + 1};
    }
  }
  return range;
}

// DP algorithm avoids overflow
//
// 1
// 1  1
// 1  2  1
// 1  3  3  1
// 1  4  6  4  1
// 1  5  10 10 5  1
// 1  6  15 20 15 6  1
//
int n_choose_k(int n, int k)
{
  // Store two rows of Pascal's triangle. Overwrite the oldest at each step using the last.
  array<vector<int>, 2> table = {vector<int>(k + 1), vector<int>(k + 1)};
  table[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    int curr_row = i & 1, last_row = (i - 1) & 1;
    table[curr_row][0] = 1;
    for (int j = 1; j <= k; ++j) {
      table[curr_row][j] = table[last_row][j] + table[last_row][j - 1];
    }
  }
  return table[n & 1][k];
}

int n_choose_k2(int n, int k)
{
  vector<Item<int> > num;
  for (int i = 0; i != n; ++i) { num.emplace_back(Item<int>{1, 1}); }

  return general_knapsack<int,Add_Op<int>,Mult_Op<int> > (num, true, k, k);
}

// int count_combinations(int s, vector<int>& score_ways)
// {
//   vector<int> combinations(s + 1, 0);
//   combinations[0] = 1;
//   for (int score : score_ways) {
//     for (int k = score; k <= s; ++k) {
//       combinations[k] += combinations[k - score];
//     }
//   }
//   return combinations[s];
// }

int count_combinations2(int s, vector<int>& score_ways)
{
  vector<Item<int> > scores;
  for (int s : score_ways) { scores.emplace_back(Item<int>{1, s}); }

  return general_knapsack<int,Add_Op<int>,Mult_Op<int> > (scores, false, s, s);
}

int count_combinations3(int s, vector<int>& score_ways)
{
  vector<vector<int> > w (score_ways.size(), vector<int>(s + 1, 0));
  w[0][0] = 1;
  for (int i = 0; i < score_ways.size(); ++i) {
    for (int k = 0; k <= s; ++k) {
      w[i][k] = (k >= score_ways[i] ? w[i][k - score_ways[i]] : 0) + (i >= 1 ? w[i - 1][k] : 0);
    }
  }
  return w[score_ways.size() - 1][s];
}

int maximize_fishing(vector<vector<int> >& A)
{
  for (int i = 0; i != A.size(); ++i) {
    for (int j = 0; j != A[i].size(); ++j) {
      A[i][j] += std::max(i < 1 ? 0 : A[i - 1][j], j < 1 ? 0 : A[i][j - 1]);
    }
  }
}

int num_paths(int m, int n)
{
  if (n < m) std::swap(n, m);
  vector<vector<int> > table(2, vector<int>(m, 1));

  for (int i = 1; i != n; ++i) {
    for (int j = 1; j != m; ++j) {
      table[i&1][j] = table[i&1][j-1] + table[(i-1)&1][j];
    }
  }

  return table[(n-1)&1][m-1];
}

int num_paths2(int m, int n)
{
  return n_choose_k2(n + m - 2, std::min(m - 1, n - 1));
}

int num_paths_with_obstacles(int m, int n, const vector<deque<bool> >& B)
{
  if (B[0][0]) return 0;

  vector<vector<int> > table(n, vector<int>(m, 0));
  table[0][0] = 1;

  for (int i = 0; i != n; ++i) {
    for (int j = 0; j != m; ++j) {
      table[i][j] = B[i][j] ? 0 : (i<1 ? 0 : table[i-1][j]) + (j<1 ? 0 : table[i][j-1]);
    }
  }

  return table.back().back();
}

int knapsack(int w, const vector<Item<int> >& items)
{
  vector<int> V(w + 1, 0);
  for (int i = 0; i != items.size(); ++i) {
    for (int k = w; k >= items[i].weight; --k) {
      V[k] = std::max(V[k], V[k - items[i].weight] + items[i].value);
    }
  }
  return V[w];
}

int knapsack2(int w, const vector<Item<int> >& items)
{
  return general_knapsack<int,Max_Op<int>,Add_Op<int> > (items, true, w, w);
}

vector<Num> generate_smallest(int k)
{
  vector<Num> result;
  set<Num> T;
  T.insert({0, 0});

  while (result.size() != k) {
    auto it = T.cbegin();
    result.emplace_back(*it);
    T.insert({it->a_+1, it->b_});
    T.insert({it->a_, it->b_+1});
    T.erase(it);
  }

  return result;
}

vector<Num> generate_smallest2(int k)
{
  vector<Num> result;
  std::priority_queue<Num> T;
  T.emplace(Num(0, 0));

  while (result.size() != k) {
    Num t = T.top();
    T.pop();
    result.emplace_back(t);
    T.emplace(Num(t.a_+1, t.b_));
    T.emplace(Num(t.a_, t.b_+1));
    T.pop();
  }

  return result;
}

vector<Num> generate_smallest3(int k)
{
  int i = 0, j = 0;
  vector<Num> result;
  result.emplace_back(Num(0, 0));
  for (int n = 0; n < k; ++n) {
    Num x(result[i].a_ + 1, result[i].b_);
    Num y(result[j].a_, result[j].b_ + sqrt(2));
    if (x < y) {
      i++;
      result.emplace_back(x);
    } else if (y < x) {
      j++;
      result.emplace_back(y);
    } else {
      i++, j++;
      result.emplace_back(x);
    }
  }
}

long long tie_election(const vector<int>& V)
{
  long long total_votes = accumulate(V.begin(), V.end(), 0);

  if (total_votes & 1) {
    return 0;
  }

  vector<vector<long long> > T(V.size() + 1, vector<long long>(total_votes + 1, 0));
  T[0][0] = 1;
  for (int i = 0; i < V.size(); ++i) {
    for (int j = 0; j <= total_votes; ++j) {
      T[i+1][j] = T[i][j] + (j >= V[i] ? T[i][j - V[i]] : 0);
    }
  }
  return T[V.size()][total_votes >> 1];
}

long long tie_election2(const vector<int>& V)
{
  typedef long long T;

  T total_votes = accumulate(V.begin(), V.end(), 0);
  if (total_votes & 1) return 0;

  vector<Item<T> > states;
  for (int votes : V) {states.emplace_back(Item<T>{1, votes});}

  return general_knapsack<T,Add_Op<T>,Mult_Op<T> > (states, true, total_votes, total_votes >> 1);
}

vector<string> word_breaking(const string& str, const vector<string>& dictionary)
{
  string s(str);
  s.erase(remove_if(s.begin(), s.end(), isspace), s.end());
  unordered_set<string> dict;
  for (const string& s : dictionary) { dict.insert(s); }

  vector<int> table(s.size(), 0);

  for (int i = 0; i != s.size(); ++i) {
    if (dict.find(s.substr(0, i + 1)) != dict.cend()) {
      table[i] = i + 1;
    }

    for (int j = 0; j != i && table[i] == 0; ++j) {
      if (table[j] != 0 && dict.find(s.substr(j + 1, i - j)) != dict.cend()) {
	table[i] = i - j;
      }
    }
  }

  vector<string> result;
  if (table.back()) {
    int idx = s.size()-1;
    while (idx >= 0) {
      result.emplace_back(s.substr(idx - table[idx] + 1, table[idx]));
      idx -= table[idx];
    }
    reverse(result.begin(), result.end());
  }

  return result;
}

double house_majority_helper(const vector<double>& prob, int r, int n, vector<vector<double> >& P)
{
  if (r > n) {
    return 0.0;
  } else if (r == 0 && n == 0) {
    return 1.0;
  } else if (r < 0) {
    return 0.0;
  }
  if (P[r][n] == -1.0) {
    P[r][n] =
      house_majority_helper(prob, r - 1, n - 1, P) * prob[n - 1] +
      house_majority_helper(prob, r, n - 1, P) * (1 - prob[n - 1]);
  }
  return P[r][n];
}

double house_majority(const vector<double>& prob, int n)
{

  vector<vector<double> > P(n + 1, vector<double>(n + 1, -1.0));

  double prob_sum = 0.0;
  for (int r = ceil(0.5 * n); r <= n; ++r) {
    prob_sum += house_majority_helper(prob, r, n, P);
  }
  return prob_sum;
}



bool is_feasible(const Coordinate<int>& coord, const vector<vector<int> >& maze)
{
  return
    (coord.x >= 0 && coord.y >= 0) &&
    (coord.x < maze.size() && coord.y < maze[coord.x].size()) &&
    (maze[coord.x][coord.y] == 0);
}

bool search_maze_helper (const Coordinate<int>& curr, const Coordinate<int>& e, vector<vector<int> >* maze, vector<Coordinate<int> >* path)
{
  if (curr == e) return true;

  // Array needs double init braces because need to init inner actual T[N] array object. Is this only true for array<array<T>> ?
  const array<array<int, 2>, 4> shift {{{{1, 0}}, {{0, 1}}, {{-1, 0}}, {{0, -1}}}};

  for (auto& s : shift) {
    const Coordinate<int> next {curr.x + s[0], curr.y + s[1]};
    if (is_feasible(next, *maze)) {
      (*maze)[next.x][next.y] = 1;
      path->emplace_back(next);
      if (search_maze_helper(next, e, maze, path)) {
	return true;
      }
      path->pop_back();
    }
  }
  return false;
}

vector<Coordinate<int> > search_maze(vector<vector<int> >& maze, const Coordinate<int>& s, const Coordinate<int>& e)
{
  vector<Coordinate<int> > path;
  maze[s.x][s.y] = 1;
  path.emplace_back(s);

  if (!search_maze_helper(s, e, &maze, &path)) {
    path.pop_back();
  }
  return path;
}

void flip_color_region(vector<vector<unsigned int> >* colors, const Coordinate<unsigned int>& co)
{
  queue<Coordinate<unsigned int> > coords;
  auto color = (*colors)[co.x][co.y];
  auto new_color = !color;
  coords.emplace(co);
  while (!coords.empty()) {
    auto curr = coords.front();
    coords.pop();
    (*colors)[curr.x][curr.y] = new_color;
    const array<array<int, 2>, 4> shift {{{{0, 1}}, {{1, 0}}, {{0, -1}}, {{-1, 0}}}};
    for (auto s : shift) {
      const Coordinate<unsigned int> next {curr.x + s[0], curr.y + s[1]};
      if ((next.x >= 0 && next.x <= colors->size()) &&
	  (next.y >= 0 && next.y <= (*colors)[next.x].size()) &&
	  ((*colors)[next.x][next.y] == color)) {
	coords.emplace(next);
      }
    }
  }
}

void print_vv(const vector<vector<unsigned int> >& v)
{
  for (int i = 0; i != v.size(); ++i) {
    for (int j = 0; j!= v[i].size(); ++j) {
      std::cout << v[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

void flip_color_region_dfs(vector<vector<unsigned int> >* colors, const Coordinate<unsigned int>& co)
{
  auto color = (*colors)[co.x][co.y];
  auto new_color = !color;
  (*colors)[co.x][co.y] = new_color;

  const array<array<int, 2>, 4> shift {{{{1, 0}}, {{0, 1}}, {{-1, 0}}, {{0, -1}}}};

  for (auto& s: shift) {
    const Coordinate<unsigned int> next {co.x + s[0], co.y + s[1]};
    if ((next.x >= 0 && next.x <= colors->size()) &&
	(next.y >= 0 && next.y <= (*colors)[next.x].size()) &&
	(*colors)[next.x][next.y] == color)
      flip_color_region_dfs(colors, next);
  }
}

void mark_region_if_surrounded(int i, int j, vector<vector<char> >* board, vector<deque<bool> >* visited) {
  array<array<int, 2>, 4> dir {{{{0, 1}}, {{-1, 0}}, {{0, -1}}, {{1, 0}}}};

  vector<pair<int,int> > q;
  (*visited)[i][j] = true;
  q.emplace_back(i, j);
  bool is_surrounded = true;
  size_t idx = 0;
  // Build up a queue of coordinates in breadth-first manner. If we ever hit the edge, the original coordinate was not surrounded
  // Never pop anything from the queue. Save the aggregate BFS queue to turn the nodes black later if needed
  while (idx < q.size()) {
    const auto curr = q[idx++];
    if (curr.first == 0 || curr.first == board->size()-1 || curr.second == 0 || curr.second == board->size()-1) {
      is_surrounded = false;
    } else {
      for (auto& d : dir) {
	const pair<int,int> next {curr.first + d[0], curr.second + d[1]};
	if (((*board)[next.first][next.second] == 'W') && !(*visited)[next.first][next.second]) {
	  (*visited)[next.first][next.second] == true;
	  q.emplace_back(next.first, next.second);
	}
      }
    }
  }

  if (is_surrounded) {
    for (auto& p : q) {
      (*board)[p.first][p.second] = 'B';
    }
  }

}

void fill_surrounded_regions(vector<vector<char> >* board)
{
  vector<deque<bool> > visited (board->size(), deque<bool>(board->front().size(), false));

  for (int i = 1; i != board->size() - 1; ++i) {
    for (int j = 1; j != board->front().size() - 1; ++j) {
      if ((*board)[i][j] == 'W' && !visited[i][j]) {
	mark_region_if_surrounded(i, j, board, &visited);
      }
    }
  }
}

GraphVertex<int>* copy_graph(GraphVertex<int>* G)
{
  if (!G) return nullptr;

  unordered_map<GraphVertex<int>*,GraphVertex<int>*> vertex_map;
  queue<GraphVertex<int>*> q;
  vertex_map.emplace(G, new GraphVertex<int>{G->label});
  q.emplace(G);
  while (!q.empty()) {
    auto v = q.front();
    q.pop();
    for (auto e : v->edges) {
      if (vertex_map.find(e) == vertex_map.cend()) {
	vertex_map.emplace(e, new GraphVertex<int>{e->label});
	q.emplace(e);
      }
      vertex_map[v]->edges.emplace_back(vertex_map[e]);
    }
  }
  return vertex_map[G];
}

shared_ptr<SGraphVertex<int> > copy_graph(const shared_ptr<SGraphVertex<int> >& G)
{
  if (!G) return nullptr;

  unordered_map<shared_ptr<SGraphVertex<int> >,shared_ptr<SGraphVertex<int> > > vertex_map;
  queue<shared_ptr<SGraphVertex<int> > > q;
  vertex_map.emplace(G, std::make_shared<SGraphVertex<int> >(SGraphVertex<int>{G->label}));
  q.emplace(G);
  while (!q.empty()) {
    auto v = q.front();
    q.pop();
    for (auto e : v->edges) {
      if (vertex_map.find(e) == vertex_map.cend()) {
	vertex_map.emplace(e, std::make_shared<SGraphVertex<int> >(SGraphVertex<int>{e->label}));
	q.emplace(e);
      }
      vertex_map[v]->edges.emplace_back(vertex_map[e]);
    }
  }
  return vertex_map[G];
}

bool assignment_BFS(GraphVertex2<int>* s)
{
  queue<GraphVertex2<int>* > q;
  q.emplace(s);
  for (auto& t : q.front()->edges) {
    if (t->d == -1) {
      t->d = q.front()->d + 1;
      q.emplace(t);
    } else if (t->d == q.front()->d) {
      return false;
    }
    q.pop();
  }
  return true;
}

bool is_any_placement_feasible(vector<GraphVertex2<int> >* G)
{
  for (GraphVertex2<int>& v : *G) {
    if (v.d == -1) {
      if (!assignment_BFS(&v)) {
	return false;
      }
    }
  }
  return true;
}

int merge_count(vector<int>& A, int start, int mid, int end)
{
  int i = start, j = mid, result = 0;
  vector<int> sorted_A;
  while (i != mid && j != end) {
    if (A[i] < A[j]) {
      sorted_A.emplace_back(A[i++]);
    } else {
      result += (mid - i);
      sorted_A.emplace_back(A[j++]);
    }
  }
  copy(A.begin() + i, A.begin() + mid, back_inserter(sorted_A));
  copy(A.begin() + j, A.begin() + end, back_inserter(sorted_A));
  copy(sorted_A.begin(), sorted_A.end(), A.begin() + start);
  return result;
}

int inverted_pairs(vector<int>& A, int start, int end)
{
  if (end - start <= 1) { return 0; }
  int mid = start + (end - start) / 2;
  return inverted_pairs(A, start, mid) + inverted_pairs(A, mid, end) + merge_count(A, start, mid, end);
}

pair<double,double> compute_height_diameter(const unique_ptr<TreeVertex<int> >& T)
{
  if (!T) return {0.0, 0.0};
  array<double, 2> h {{0.0, 0.0}};
  double diameter = 0.0;

  for (auto& e : T->edges) {
    auto h_d = compute_height_diameter(e.first);
    if (h_d.first + e.second > h[0]) {
      h[1] = h[0];
      h[0] = h_d.first + e.second;
    } else if (h_d.first + e.second > h[1]) {
      h[1] = h_d.first + e.second;
    }
    diameter = max(diameter, h_d.second);
  }
  return {h[0], max(diameter, h[0] + h[1])};
}

double diameter(const unique_ptr<TreeVertex<int> >& T)
{
  return T? compute_height_diameter(T).second : 0.0;
}

bool dfs_2_exist(ColoredVertex* curr, const ColoredVertex* pre)
{
  if (curr->color == ColoredVertex::gray) {
    return true;
  }

  curr->color = ColoredVertex::gray;

  for (auto e : curr->edges) {
    if (e != pre && e->color != ColoredVertex::black) {
      if (dfs_2_exist(e, curr)) {
	return true;
      }
    }
  }
  curr->color = ColoredVertex::black;
  return false;
}

bool is_2_exist(vector<ColoredVertex>* G)
{
  if (!G->empty()) {
    return dfs_2_exist(&G->front(), nullptr);
  }
  return false;
}

bool dfs_2_all(DLVertex* curr, DLVertex* pre, int time)
{
  curr->d = time++;
  curr->l = std::numeric_limits<int>::max();

  for (auto next : curr->edges) {
    if (next != pre) {
      if (next->d != 0) {
	// back edge
	curr->l = min(curr->l, next->d);
      } else {
	// forward edge
	if (!dfs_2_all(next, curr, time)) {
	  return false;
	}
	curr->l = min(curr->l, next->l);
      }
    }
  }
  return (pre == nullptr || curr->l < curr->d);
}

bool is_2_all(vector<DLVertex>* G)
{
  if (!G->empty()) {
    return dfs_2_all(&G->front(), nullptr, 0);
  }
  return false;
}

// Not solved
int water_tapped_2(const vector<int>& A)
{
  int h_max = distance(A.begin(), max_element(A.begin(), A.end()));

  int sum = 0, rmax = 0;
  for (int i = 0; i < h_max; ++i) {
    rmax = max(rmax, A[i]);
    sum += rmax - A[i];
  }

  // How to get the other half???
  return 0;
}

// Not working yet
bool two_sum_abs(const vector<int>& A, int k)
{
  int i = 0, j = A.size() - 1;
  if (A[i] + A[j] == k) {
    return true;
  } else if (A[i] + A[j] < k) {
    if ((A[i] < 0) && (A[j] < 0)) {
      i++;
    } else if (A[i] > 0 && A[j] > 0) {
      i++;
    } else if (A[i] < 0) {
      i++;
    } else {

    }
    return false;
  }
}
