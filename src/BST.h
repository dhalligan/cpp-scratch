#include <stack>
#include <queue>

#include "make_unique.h"

using std::unique_ptr;
using std::vector;
using std::stack;
using std::queue;
using std::max;
using std::abs;
using std::pair;

template <class T>
struct BSTNode {
  T data;
  unique_ptr<BSTNode<T> > left, right;
  BSTNode<T>* parent; // not used
};

template <class T>
class BST
{
public:
  BST() {}
  BST(T values[], size_t num_values) : root_(std::move(this->build_bst(values, 0, num_values - 1))) {}
  bool empty() const { return !root_; }
  bool insert(const T& e) {
    if (!root_) {
      root_ = unique_ptr<BSTNode<T> >(new BSTNode<T>{e, nullptr, nullptr});
      return true;
    } else {
      return insert_impl(root_, e);
    }
  }
  bool find(const T& e) const {
    return root_ ? find_impl(root_, e) : false;
  }
  void erase(const T& e) {
    if (!root_) { return; }
    if (root_->data == e) {
      auto aux = unique_ptr<BSTNode<T> >(new BSTNode<T>{T(), std::move(root_), nullptr});
      erase_impl(aux, nullptr, e);
      root_ = std::move(aux->left);
    } else {
      erase_impl(root_, nullptr, e);
    }
  }
  void print() const;
  bool check() const {
    return check_impl_2(root_, std::numeric_limits<T>::min(), std::numeric_limits<T>::max());
  }
  vector<T> inorder() const {
    vector<T> result;
    inorder_impl(root_, result);
    return result;
  }
// Doesn't work yet because need to set up parent pointers
  vector<T> inorder_successor() const {
    vector<T> result;
    auto node = root_.get();
    while (node) {
      result.emplace_back(node->data);
      node = this->successor(node);
    }
    return result;
  }
  vector<T> preorder1() const {
    vector<T> result;
    preorder_impl_1(root_, result);
    return result;
  }
  vector<T> preorder2() const {
    vector<T> result;
    preorder_impl_2(root_, result);
    return result;
  }
  vector<T> postorder1() const {
    vector<T> result;
    postorder_recursive_impl(root_, result);
    return result;
  }
  vector<T> postorder2() const {
    vector<T> result;
    postorder_impl_1(root_, result);
    return result;
  }
  vector<T> postorder3() const {
    vector<T> result;
    postorder_impl_2(root_, result);
    return result;
  }
  vector<T> topologicalorder() const {
    vector<T> result;
    topologicalorder_impl(root_, result);
    return result;
  }
  vector<T> k_largest(const size_t k) const {
    vector<T> result;
    k_largest_impl(root_, k, result);
    return result;
  }
  vector<T> k_smallest(const size_t k) const {
    vector<T> result;
    k_smallest_impl(root_, k, result);
    return result;
  }
  bool balanced() const {
    return balanced_height(root_) != -2;
  }
  size_t height() const {
    return height_impl(root_);
  }
  bool symmetric() const {
    return symmetric_impl(root_->left, root_->right);
  }
  bool k_balanced(size_t k) const {
    return !k_balanced_nodes(k, root_).first;
  }
  BSTNode<T>* lca(const unique_ptr<BSTNode<T> >& x, const unique_ptr<BSTNode<T> >& y) const {
    return lca_impl(root_, x, y);
  }

private:
  unique_ptr<BSTNode<T> > root_;

  unique_ptr<BSTNode<T> > build_bst(T data[], int l, int u);
  bool insert_impl(unique_ptr<BSTNode<T> >& node, const T& data);
  bool find_recursive_impl(const unique_ptr<BSTNode<T> >& node, const T& data) const;
  bool find_impl(const unique_ptr<BSTNode<T> >& node, const T& data) const;
  T min(const unique_ptr<BSTNode<T> >& node) const;
  bool erase_impl(const unique_ptr<BSTNode<T> >& node, BSTNode<T>* parent, const T& data);
  bool check_impl_1(const unique_ptr<BSTNode<T> >& node, T min, T max) const;
  bool check_impl_2(const unique_ptr<BSTNode<T> >& node, T min, T max) const;
  void inorder_recursive_impl(const unique_ptr<BSTNode<T> >& node, vector<T>& result) const;
  void inorder_impl(const unique_ptr<BSTNode<T> >& node, vector<T>& result) const;
  void preorder_recursive_impl(const unique_ptr<BSTNode<T> >& node, vector<T>& result) const;
  void preorder_impl_1(const unique_ptr<BSTNode<T> >& node, vector<T>& result) const;
  void preorder_impl_2(const unique_ptr<BSTNode<T> >& node, vector<T>& result) const;
  void postorder_recursive_impl(const unique_ptr<BSTNode<T> >& node, vector<T>& result) const;
  void postorder_impl_1(const unique_ptr<BSTNode<T> >& node, vector<T>& result) const;
  void postorder_impl_2(const unique_ptr<BSTNode<T> >& node, vector<T>& result) const;
  void reverse_preorder_impl(const unique_ptr<BSTNode<T> >& node, vector<T>& result) const;
  void topologicalorder_impl(const unique_ptr<BSTNode<T> >& node, vector<T>& result) const;
  void k_largest_impl(const unique_ptr<BSTNode<T> >& node, const size_t k, vector<T>& result) const;
  void k_smallest_impl(const unique_ptr<BSTNode<T> >& node, const size_t k, vector<T>& result) const;
  int balanced_height(const unique_ptr<BSTNode<T> >& node) const;
  int height_impl(const unique_ptr<BSTNode<T> >& node) const;
  bool symmetric_impl(const unique_ptr<BSTNode<T> >& l, const unique_ptr<BSTNode<T> >& r) const;
  int depth(const unique_ptr<BSTNode<T> >& node) const;
  BSTNode<T>* lca_impl(const unique_ptr<BSTNode<T> >& r, const unique_ptr<BSTNode<T> >& x, const unique_ptr<BSTNode<T> >& y) const;
  pair<BSTNode<T>*,int> k_balanced_nodes(size_t k, const unique_ptr<BSTNode<T> >& node) const;
  BSTNode<T>* successor(BSTNode<T>* node) const;

};

template <class T>
unique_ptr<BSTNode<T> > BST<T>::build_bst(T data[], int l, int u)
{
  if (u < l) { return nullptr; }
  int mid = (l > 0) == (u > 0) ? l + (u - l) / 2 : (l + u) / 2;
  return unique_ptr<BSTNode<T> >(new BSTNode<T>{data[mid], std::move(this->build_bst(data, l, mid - 1)), std::move(this->build_bst(data, mid + 1, u))});
}

template <class T>
bool BST<T>::insert_impl(unique_ptr<BSTNode<T> >& node, const T& data)
{
  if (node->data == data) { return false; }
  if (data < node->data) {
    if (node->left) {
      return insert_impl(node->left, data);
    } else {
      node->left = unique_ptr<BSTNode<T> >(new BSTNode<T>{data, nullptr, nullptr});
    }
    return true;
  } else {
    if (node->right) {
      return insert_impl(node->right, data);
    } else {
      node->right = unique_ptr<BSTNode<T> >(new BSTNode<T>{data, nullptr, nullptr});
    }
    return true;
  }
}

template <class T>
bool BST<T>::find_recursive_impl(const unique_ptr<BSTNode<T> >& node, const T& data) const
{
  if (!node) { return false; }

  if (node->data == data) {
    return true;
  } else {
    return find_recursive_impl(data < node->data ? node->left : node->right, data);
  }
}

template <class T>
bool BST<T>::find_impl(const unique_ptr<BSTNode<T> >& node, const T& data) const
{
  if (!node) { return false; }

  auto curr = node.get();
  while (curr) {
    if (curr->data == data) {
      return true;
    } else {
      curr = data < curr->data ? curr->left.get() : curr->right.get();
    }
  }
  return false;
}

template <class T>
T BST<T>::min(const unique_ptr<BSTNode<T> >& node) const
{
  return node->left ? min(node->left) : node->data;
}

template <class T>
bool BST<T>::erase_impl(const unique_ptr<BSTNode<T> >& node, BSTNode<T>* parent, const T& data)
{
  if (!node) { return false; }

  if (node->data == data) {
    if (node->left && node->right) {
      node->data = min(node->right);
      return erase_impl(node->right, node.get(), data);
    } else {
      if (parent->left == node) {
	parent->left = std::move(node->left ? node->left : node->right);
      } else {
	parent->right = std::move(node->left ? node->left : node->right);
      }
      return true;
    }
  } else {
    return erase_impl(data < node->data ? node->left : node->right, node.get(), data);
  }
}

template <class T>
bool BST<T>::check_impl_1(const unique_ptr<BSTNode<T> >& node, T min, T max) const
{
  if (!node) { return true; }

  if (min > node->data || max < node->data) {
    return false;
  } else {
    return check_impl(node->left, min, node->data) && check_impl(node->right, node->data, max);
  }
}

template <class T>
bool BST<T>::check_impl_2(const unique_ptr<BSTNode<T> >& node, T min, T max) const
{
  if (!node) { return true; }

  vector<T> inorder = this->inorder();
  for (size_t i = 1; i < inorder.size(); ++i) {
    if (inorder[i] < inorder[i-1]) { return false; }
  }
  return true;
}

template <class T>
void BST<T>::inorder_recursive_impl(const unique_ptr<BSTNode<T> >& node, vector<T>& result) const
{
  if (!node) { return; }
  inorder_recursive_impl(node->left, result);
  result.emplace_back(node->data);
  inorder_recursive_impl(node->right, result);
}

template <class T>
void BST<T>::preorder_recursive_impl(const unique_ptr<BSTNode<T> >& node, vector<T>& result) const
{
  if (!node) { return; }
  result.emplace_back(node->data);
  preorder_recursive_impl(node->left, result);
  preorder_recursive_impl(node->right, result);
}

template <class T>
void BST<T>::postorder_recursive_impl(const unique_ptr<BSTNode<T> >& node, vector<T>& result) const
{
  if (!node) { return; }
  postorder_recursive_impl(node->left, result);
  postorder_recursive_impl(node->right, result);
  result.emplace_back(node->data);
}

template <class T>
void BST<T>::inorder_impl(const unique_ptr<BSTNode<T> >& node, vector<T>& result) const
{
  stack<BSTNode<T>* > s;
  auto curr = node.get();

  while (!s.empty() || curr) {
    if (curr) {
      s.emplace(curr);
      curr = curr->left.get();
    } else {
      curr = s.top();
      s.pop();
      result.emplace_back(curr->data);
      curr = curr->right.get();
    }
  }
}

template <class T>
void BST<T>::preorder_impl_1(const unique_ptr<BSTNode<T> >& node, vector<T>& result) const
{
  stack<BSTNode<T>* > s;
  auto curr = node.get();

  while (!s.empty() || curr) {
    if (curr) {
      result.emplace_back(curr->data);
      s.emplace(curr);
      curr = curr->left.get();
    } else {
      curr = s.top();
      s.pop();
      curr = curr->right.get();
    }
  }
}

template <class T>
void BST<T>::preorder_impl_2(const unique_ptr<BSTNode<T> >& node, vector<T>& result) const
{
  stack<BSTNode<T>* > s;
  s.emplace(node.get());

  while (!s.empty()) {
    auto curr = s.top();
    s.pop();
    result.emplace_back(curr->data);
    if (curr->right) { s.emplace(curr->right.get()); }
    if (curr->left) { s.emplace(curr->left.get()); }
  }
}

template <class T>
void BST<T>::postorder_impl_1(const unique_ptr<BSTNode<T> >& node, vector<T>& result) const
{
  stack<BSTNode<T>* > s;
  BSTNode<T>* curr = node.get();
  BSTNode<T>* last = nullptr;

  while (!s.empty() || curr) {
    if (curr) {
      s.emplace(curr);
      curr = curr->left.get();
    } else {
      auto t = s.top();
      if (t->right && last != t->right.get()) {
      	curr = t->right.get();
      } else {
	result.emplace_back(t->data);
	last = t;
	s.pop();
      }
    }
  }
}

template <class T>
void BST<T>::reverse_preorder_impl(const unique_ptr<BSTNode<T> >& node, vector<T>& result) const
{
  stack<BSTNode<T>* > s;
  s.emplace(node.get());

  while (!s.empty()) {
    auto curr = s.top();
    s.pop();
    result.emplace_back(curr->data);
    if (curr->left) { s.emplace(curr->left.get()); }
    if (curr->right) { s.emplace(curr->right.get()); }
  }
}

template <class T>
void BST<T>::postorder_impl_2(const unique_ptr<BSTNode<T> >& node, vector<T>& result) const
{
  reverse_preorder_impl(node, result);
  reverse(result.begin(), result.end());
}

template <class T>
void BST<T>::topologicalorder_impl(const unique_ptr<BSTNode<T> >& node, vector<T>& result) const
{
  postorder_impl_1(node, result);
  reverse(result.begin(), result.end());
}

template <class T>
void BST<T>::k_largest_impl(const unique_ptr<BSTNode<T> >& node, const size_t k, vector<T>& result) const
{
  if (!node) { return; }
  if (result.size() < k) {
    k_largest_impl(node->right, k, result);
    if (result.size() < k) {
      result.emplace_back(node->data);
      k_largest_impl(node->left, k, result);
    }
  }
}

template <class T>
void BST<T>::k_smallest_impl(const unique_ptr<BSTNode<T> >& node, const size_t k, vector<T>& result) const
{
  if (!node) { return; }
  if (result.size() < k) {
    k_smallest_impl(node->left, k, result);
    if (result.size() < k) {
      result.emplace_back(node->data);
      k_smallest_impl(node->right, k, result);
    }
  }
}

template <class T>
int BST<T>::balanced_height(const unique_ptr<BSTNode<T> >& node) const
{
  if (!node) { return -1; }

  auto lheight = balanced_height(node->left);
  if (lheight == -2) return -2;
  auto rheight = balanced_height(node->right);
  if (rheight == -2) return -2;

  return abs(lheight - rheight) > 1 ? -2 : max(lheight, rheight) + 1;
}

template <class T>
pair<BSTNode<T>*,int> BST<T>::k_balanced_nodes(size_t k, const unique_ptr<BSTNode<T> >& node) const
{
  if (!node) { return {nullptr,0}; }

  auto lnodes = k_balanced_nodes(k, node->left);
  if (lnodes.first) return lnodes;
  auto rnodes = k_balanced_nodes(k, node->right);
  if (rnodes.first) return rnodes;

  return {abs(lnodes.second - rnodes.second) > k ? node.get() : nullptr, lnodes.second + rnodes.second + 1};
}

template <class T>
int BST<T>::height_impl(const unique_ptr<BSTNode<T> >& node) const
{
  if (!node) { return -1; }

  auto lheight = height_impl(node->left);
  auto rheight = height_impl(node->right);

  return max(lheight, rheight) + 1;
}

template <class T>
bool BST<T>::symmetric_impl(const unique_ptr<BSTNode<T> >& l, const unique_ptr<BSTNode<T> >& r) const
{
  if (!l && !r) { return true; }
  return
    (l && r) &&
    (l->data == r->data) &&
    symmetric_impl(l->right, r->left) &&
    symmetric_impl(l->left, r->right);
}

template <class T>
BSTNode<T>* BST<T>::lca_impl(const unique_ptr<BSTNode<T> >& r, const unique_ptr<BSTNode<T> >& x, const unique_ptr<BSTNode<T> >& y) const
{
  if (!r) { return nullptr; }

  // This is x or y
  if (r == x || r == y) { return r.get(); }

  auto left = lca_impl(r->left, x, y);
  auto right = lca_impl(r->right, x, y);

  // x, y are in differeny subtrees; this is the lca
  if (left && right) { return r.get(); }

  // x, y are in same subtree; propagate lca result
  return left ? left : right;
}

// Doesn't work yet because need to set up parent pointers
template <class T>
BSTNode<T>* BST<T>::successor(BSTNode<T>* node) const
{
  if (!node) { return nullptr; }
  if (node->right) {
    auto curr = node->right.get();
    while (curr->left) {
      curr = curr->left.get();
    }
    return curr;
  } else if (node->parent) {
    auto curr = node->parent;
    auto prev = node;
    while (curr && curr->left.get() != prev) {
      prev = curr;
      curr = curr->parent;
    }
    return curr;
  }
}

template <class T>
void  BST<T>::print() const
{
  queue<BSTNode<T>* > q;
  q.emplace(root_.get());
  auto count = q.size();

  while (!q.empty()) {
    std::cout << q.front()->data << " ";
    if (q.front()->left) { q.push(q.front()->left.get()); }
    if (q.front()->right) { q.push(q.front()->right.get()); }
    q.pop();
    if (--count == 0) {
      std::cout << std::endl;
      count = q.size();
    }
  }
}
