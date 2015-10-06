#include "convenience.hpp"

#include <stack>

struct Node;

using NodePtr = unique_ptr<Node>;

struct Node {
  int data;
  NodePtr l, r;
};

NodePtr node(int data, NodePtr l = nullptr, NodePtr r = nullptr) {
  return unique_ptr<Node>(new Node{data, move(l), move(r)});
}

bool find_node(Node* to_find, Node* cur, vector<Node*>& path) {
  cout << to_find << " " << cur << endl;
  if (to_find == cur)
    return true;
  else {
    if (cur->l != nullptr) {
      path.push_back(cur->l.get());
      bool found = find_node(to_find, cur->l.get(), path);
      if (found) return true;
      path.pop_back();
    }
    if (cur->r != nullptr) {
      path.push_back(cur->r.get());
      bool found = find_node(to_find, cur->r.get(), path);
      if (found) return true;
      path.pop_back();
    }
    return false;
  }
  return false;
}

Node* find_lca(Node* n1, Node* n2, Node* root) {
  vector<Node*> path1;
  vector<Node*> path2;
  bool found1 = find_node(n1, root, path1);
  bool found2 = find_node(n2, root, path2);
  cout << "path1 = " << path1 << endl;
  cout << "path2 = " << path2 << endl;
  cout << found1 << found2 << endl;
  if (found1 == false || found2 == false) {
    return nullptr;
  } else {
    int i = 0;
    Node* last_common = root;
    while (i < path1.size() && i < path2.size()) {
      cout << i << " last common is " << last_common << endl;
      if (path1[i] == path2[i]) {
        last_common = path1[i];
      } else {
        break;
      }
      ++i;
    }
    return last_common;
  }
}

int main(int argc, char** args) {

  auto tree = node(1,
                   node(2, node(3), node(4)),
                   node(5, node(6), node(7)));

  cout << find_lca(tree->r->l.get(), tree->l->r.get(), tree.get()) << endl;

  return 0;
}
