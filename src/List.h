using std::shared_ptr;
using std::make_shared;
using std::unordered_map;

template <class T>
struct ListNode {
  T data;
  shared_ptr<ListNode<T> > next;
};

template <class T>
class List
{
public:
  bool empty() const {
    return !head_;
  }
  size_t size() const {
    return size_iterative();
  }
  T front() const {
    return head_->data;
  }
  T back() const {
    return tail_->data;
  }
  void push_back(const T& e) {
    auto node = make_shared<ListNode<T> >(); node->data = e;
    push_back_impl(node, &head_, &tail_);
  }
  void push_front(const T& e) {
    auto node = make_shared<ListNode<T> >(); node->data = e;
    push_front_impl(node, &head_);
  }
  void pop_front() {
    pop_front_impl(&head_);
  }
  size_t size_recursive_1() const {
    return size_recursive_impl_1(head_);
  }
  size_t size_recursive_2() const {
    return size_recursive_impl_2(head_, 0);
  }
  size_t size_iterative() const {
    return size_iterative_impl(head_);
  }
  void reverse() {
    tail_ = head_;
    head_ = reverse_impl(head_);
  }
  shared_ptr<ListNode<T> > find_cycle(const shared_ptr<ListNode<T> >& node)
  {
    return find_cycle_impl(node);
  }
  bool palindromic() {
    return palindromic_impl(head_);
  }
  void remove(const T& e) {
    remove_impl(head_, e);
  }
  void unique() {
    unique_impl(head_);
  }
  void remove_duplicates() {
    remove_duplicates_impl(head_);
  }
  T median() {
    return median_impl(head_);
  }
  void print() const {
    for (auto p = head_; p; p = p->next) {
      std::cout << p->data << " ";
    }
    std::cout << std::endl;
  }

private:
  shared_ptr<ListNode<T> > head_, tail_;

  void push_back_impl(const shared_ptr<ListNode<T> >& node, shared_ptr<ListNode<T> >* head, shared_ptr<ListNode<T> >* tail);
  void push_front_impl(const shared_ptr<ListNode<T> >& node, shared_ptr<ListNode<T> >* head);
  void pop_front_impl(shared_ptr<ListNode<T> >* head);
  void push_back_and_advance(shared_ptr<ListNode<T> >* node, shared_ptr<ListNode<T> >* head, shared_ptr<ListNode<T> >* tail);
  shared_ptr<ListNode<T> > reverse_impl(shared_ptr<ListNode<T> >& node);
  shared_ptr<ListNode<T> > merge_impl(shared_ptr<ListNode<T> > f, shared_ptr<ListNode<T> > l);
  void delete_node(const shared_ptr<ListNode<T> >& node);
  void delete_next_node(const shared_ptr<ListNode<T> >& node);
  shared_ptr<ListNode<T> > kth_last(size_t k, const shared_ptr<ListNode<T> >& node);
  void delete_kth_last(size_t k, const shared_ptr<ListNode<T> >& node);
  shared_ptr<ListNode<T> > find_cycle_impl(const shared_ptr<ListNode<T> >& node);
  T median_impl(const shared_ptr<ListNode<T> >& node);
  T median_circular_impl(const shared_ptr<ListNode<T> >& node);
  bool palindromic_impl(shared_ptr<ListNode<T> >& node);
  void remove_impl(const shared_ptr<ListNode<T> >& node, const T& e);
  void unique_impl(const shared_ptr<ListNode<T> >& node);
  void remove_duplicates_impl(const shared_ptr<ListNode<T> >& node);
  size_t size_recursive_impl_1(const shared_ptr<ListNode<T> >& node) const;
  size_t size_recursive_impl_2(const shared_ptr<ListNode<T> >& node, size_t count) const;
  size_t size_iterative_impl(const shared_ptr<ListNode<T> >& node) const;
};

template <class T>
void List<T>::push_back_impl(const shared_ptr<ListNode<T> >& node, shared_ptr<ListNode<T> >* head, shared_ptr<ListNode<T> >* tail)
{
  *head ? (*tail)->next = node : *head = node;
  *tail = node;
}

template <class T>
void List<T>::push_front_impl(const shared_ptr<ListNode<T> >& node, shared_ptr<ListNode<T> >* head)
{
  node->next = *head;
  *head = node;
}

template <class T>
void List<T>::pop_front_impl(shared_ptr<ListNode<T> >* head)
{
  *head = *head ? (*head)->next : *head;
}

template <class T>
void List<T>::push_back_and_advance(shared_ptr<ListNode<T> >* node, shared_ptr<ListNode<T> >* head, shared_ptr<ListNode<T> >* tail)
{
  push_back_impl(*node, head, tail);
  (*node) = (*node)->next;
}

template <class T>
shared_ptr<ListNode<T> > List<T>::merge_impl(shared_ptr<ListNode<T> > f, shared_ptr<ListNode<T> > l)
{
  shared_ptr<ListNode<T> > sorted_head = nullptr, sorted_tail = nullptr;
  while (f && l) {
    push_back_and_advance(f->data < l->data ? &f : &l, &sorted_head, &sorted_tail);
  }
  if (f) {
    push_back_impl(f, &sorted_head, &sorted_tail);
  }
  if (l) {
    push_back_impl(l, &sorted_head, &sorted_tail);
  }
  return sorted_head;
}

template <class T>
shared_ptr<ListNode<T> > List<T>::reverse_impl(shared_ptr<ListNode<T> >& node)
{
  shared_ptr<ListNode<T> > prev = nullptr, curr = node;
  while (curr) {
    auto temp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = temp;
  }
  return prev;
}

template <class T>
bool List<T>::palindromic_impl(shared_ptr<ListNode<T> >& node)
{
  shared_ptr<ListNode<T> > front = node, curr = node, ahead = node;
  while (ahead) {
    ahead = ahead->next;
    if (ahead) {
      ahead = ahead->next;
      curr = curr->next;
    }
  }
  auto back = reverse_impl(curr);
  while (back && front) {
    if (back->data != front->data) { return false; }
    back = back->next;
    front = front->next;
  }
  return true;
}

template <class T>
List<T> merge(List<T> x, List<T> y)
{
  List<T> result;
  return result;
}

template <class T>
void List<T>::delete_node(const shared_ptr<ListNode<T> >& node)
{
  if (node->next) {
    node->data = node->next->data;
    node->next = node->next->next;
  }
}

template <class T>
void List<T>::delete_next_node(const shared_ptr<ListNode<T> >& node)
{
  if (node->next) {
    node->next = node->next->next;
  }
}

template <class T>
shared_ptr<ListNode<T> > List<T>::kth_last(size_t k, const shared_ptr<ListNode<T> >& node)
{
  auto curr = node, ahead = node;
  while (k--) { ahead = ahead->next; }
  while (ahead) { curr = curr->next; ahead = ahead->next; }
  return curr;
}

template <class T>
void List<T>::delete_kth_last(size_t k, const shared_ptr<ListNode<T> >& node)
{
  bool last = (k == 1);
  if (last && !node->next) { node = nullptr; return; }
  if (last) { k = 2; }

  auto curr = kth_last(k, node);

  if (last) {
    delete_next_node(curr);
  } else {
    delete_node(curr);
  }
}

template <class T>
shared_ptr<ListNode<T> > List<T>::find_cycle_impl(const shared_ptr<ListNode<T> >& node)
{
  auto slow = node, fast = node;
  while (slow && slow->next && fast && fast->next && fast->next->next) {
    slow = slow->next; fast = fast->next->next;
    // Detect cycle
    if (slow == fast) {
      // There is a cycle. Find cycle length.
      size_t length = 0;
      do { fast = fast->next; length++; } while (fast != slow);
      // Find beginning of cycle.
      slow = node; fast = node;
      while (length--) { fast = fast->next; }
      while (slow != fast) { slow = slow->next; fast = fast->next; }
      return slow;
    }
  }
  // There is no cycle.
  return nullptr;
}

template <class T>
T List<T>::median_impl(const shared_ptr<ListNode<T> >& node)
{
  size_t length = this->size();
  auto mid = node;
  for (size_t i = 0; i < length / 2; ++i) {
    mid = mid->next;
  }
  return length & 1 ? mid->data : 0.5 * (mid->data + mid->next->data);
}

template <class T>
T List<T>::median_circular_impl(const shared_ptr<ListNode<T> >& node)
{
  size_t length = 0;
  auto curr = node, start = node;
  do {
    curr = curr->next;
    length++;
    if (curr->data <= start->data) {
      start = curr;
    }
  } while (curr != node);

  for (size_t i = 0; i < length / 2; ++i) {
    start = start->next;
  }
  return length & 1 ? start->data : 0.5 * (start->data + start->next->data);
}

template <class T>
void List<T>::remove_impl(const shared_ptr<ListNode<T> >& node, const T& e)
{
  while (node && node->data == e) { node = node->next; }
  auto curr = node->next, prev = node;

  while (curr) {
    if (curr->data != e) {
      prev->next = curr;
      prev = curr;
    }
    curr = curr->next;
  }
  // The last group of nodes with equal data
  prev->next = nullptr;
}

template <class T>
void List<T>::unique_impl(const shared_ptr<ListNode<T> >& node)
{
  auto curr = node, ahead = node;
  while (ahead) {
    if (ahead->data != curr->data) {
      curr->next = ahead;
      curr = ahead;
    }
    ahead = ahead->next;
  }
  // The last group of nodes with equal data
  curr->next = nullptr;
}

template <class T>
void List<T>::remove_duplicates_impl(const shared_ptr<ListNode<T> >& node)
{
  unordered_map<T,size_t> count;
  shared_ptr<ListNode<T> > curr = node, prev = nullptr;
  while (curr) {
    if (count.find(curr->data) != count.cend()) {
      prev->next = curr->next;
    } else {
      count[curr->data]++;
      prev = curr;
    }
    curr = curr->next;
  }
}

template <class T>
size_t List<T>::size_recursive_impl_1(const shared_ptr<ListNode<T> >& node) const
{
  return node ? size_recursive_impl_1(node->next) + 1 : 0;
}

template <class T>
size_t List<T>::size_recursive_impl_2(const shared_ptr<ListNode<T> >& node, size_t count) const
{
  return node ? size_recursive_impl_2(node->next, count + 1) : count;
}

template <class T>
size_t List<T>::size_iterative_impl(const shared_ptr<ListNode<T> >& node) const
{
  size_t count = 0;
  auto curr = node;
  while (curr) { count++; curr = curr->next; }
  return count;
}


template <class T>
struct CListNode {
  T data;
  CListNode<T>* next;
};

template <class T>
CListNode<T>* add_two_numbers(CListNode<T> *l1, CListNode<T> *l2) {
  if (!l1) { return l2; }
  if (!l2) { return l1; }

  CListNode<T>* head = new CListNode<T>(0);
  CListNode<T>* curr = head;
  int carry = 0;
  while (l1 && l2) {
    int sum = l1->val + l2->val + carry;
    int value = sum > 9 ? sum - 10 : sum;
    carry = sum > 9 ? 1 : 0;
    curr->next = new CListNode<T>(value);
    curr = curr->next, l1 = l1->next, l2 = l2->next;
  }

  while (l1) {
    int sum = l1->val + carry;
    int value = sum > 9 ? sum - 10 : sum;
    carry = sum > 9 ? 1 : 0;
    curr->next = new CListNode<T>(value);
    curr = curr->next, l1 = l1->next;
  }

  while (l2) {
    int sum = l2->val + carry;
    int value = sum > 9 ? sum - 10 : sum;
    carry = sum > 9 ? 1 : 0;
    curr->next = new CListNode<T>(value);
    curr = curr->next, l2 = l2->next;
  }

  if (carry != 0) {
    curr->next = new CListNode<T>(carry);
  }

  return head->next;
}

template <class T>
CListNode<T> *mergeTwoLists(CListNode<T> *l1, CListNode<T> *l2) {
  CListNode<T>* head = new CListNode<T>(0);
  CListNode<T>* curr = head;

  while (l1 && l2) {
    if (l1->value < l2->value) {
      curr->next = new CListNode<T>(l1->value);
      curr = curr->next; l1 = l1->next;
    } else {
      curr->next = new CListNode<T>(l2->value);
      curr = curr->next; l2 = l2->next;
    }
  }

  if (l1) {
    curr->next = l1;
  }

  if (l2) {
    curr->next = l2;
  }

  return head->next;
}
