#include <iostream>
#include <queue>

using std::cout;
using std::endl;
using std::queue;

template <class T, class W>
class Vertex
{
public:
  Vertex(T d) : data(d) {}
  void add_edge(Vertex<T, W>* vertex, W weight) {
    edges.emplace_back(vertex, weight);
  }

  T data;  
  enum class Color {white, gray, black} color = Color::white;
  vector<pair<Vertex<T, W>*, W> > edges;
};

template <class T, class W>
bool is_reachable_dfs(Vertex<T, W>* s, Vertex<T, W>* f)
{
  if (s == f) { return true; }

  s->color = Vertex<T, W>::Color::gray;
  for (auto e : s->edges) {
    if (e.first->color == Vertex<T, W>::Color::white) {
      if (is_reachable(e.first, f)) { return true; }
    }
  }
  s->color = Vertex<T, W>::Color::black;
  return false;
}

template <class T, class W>
bool is_reachable_bfs(Vertex<T, W>* s, Vertex<T, W>* f)
{
  queue<Vertex<T, W>* > q;
  q.emplace(s);

  while (!q.empty()) {
    auto v = q.front();
    q.pop();
    if (v == f) { return true; }
    v->color = Vertex<T, W>::Color::black;
    for (auto e : v->edges) {
      if (e.first->color == Vertex<T, W>::Color::white) {
	q.emplace(e.first);
      }
    }
  }
  return false;
}
