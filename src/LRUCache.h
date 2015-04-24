#include <unordered_map>
#include <list>

using std::unordered_map;
using std::list;
using std::pair;

/*
  LRUCache implements a simple cache with LRU (least recently used) replacement policy
*/
template <class K, class V, size_t capacity>
class LRUCache
{
public:
  bool lookup(K key, V* value);
  void insert(K key, V value);
  bool erase(K key);

private:
  typedef unordered_map<K,pair<typename list<K>::iterator,V> > Table;
  list<K> lru_data_;
  Table cache_;

  void move_to_front(const typename Table::iterator& it);

};

template <class K, class V, size_t capacity>
bool LRUCache<K, V, capacity>::lookup(K key, V* value)
{
  auto it = cache_.find(key);
  if (it == cache_.cend()) {
    return false;
  }

  *value = it->second.second;
  move_to_front(it);
  return true;
}

template <class K, class V, size_t capacity>
void LRUCache<K, V, capacity>::insert(K key, V value)
{
  auto it = cache_.find(key);
  if (it != cache_.cend()) {
    move_to_front(it);
    return;
  }

  if (cache_.size() == capacity) {
    cache_.erase(lru_data_.back());
    lru_data_.pop_back();
  }
  lru_data_.emplace_front(key);
  cache_[key] = {lru_data_.begin(), value};
}

template <class K, class V, size_t capacity>
bool LRUCache<K, V, capacity>::erase(K key)
{
  auto it = cache_.find(key);
  if (it == cache_.cend()) {
    return false;
  }

  lru_data_.erase(it->second.first);
  cache_.erase(it);
  return true;
}

template <class K, class V, size_t capacity>
void LRUCache<K, V, capacity>::move_to_front(const typename Table::iterator& it)
{
  lru_data_.erase(it->second.first);
  lru_data_.emplace_front(it->first);
  it->second.first = lru_data_.begin();
}
