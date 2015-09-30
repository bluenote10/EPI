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


bool is_identical(Node* n1, Node* n2) {
  if (n1 == nullptr)
    return n2 == nullptr;
  else
    return n1->data == n2->data;
}

bool is_identical(const NodePtr& root) {
  Node* t1 = root->l.get();
  Node* t2 = root->r.get();

  stack<pair<Node*, Node*>> stack;

  stack.emplace(t1, t2);

  while (stack.size() > 0) {
    auto next = stack.top();
    stack.pop();
    auto n1 = next.first;
    auto n2 = next.second;
    cout << (n1 ? n1->data : -1) << " " << (n2 ? n2->data : -1) << endl;
    if (!is_identical(n1, n2))
      return false;
    if (n1 != nullptr) {
      stack.emplace(n1->l.get(), n2->l.get());
      stack.emplace(n1->r.get(), n2->r.get());
    }
  }

  return true;
}

bool is_symmetric_rec(const NodePtr& t1, const NodePtr& t2) {
  cout << (t1 ? t1->data : -1) << " " << (t2 ? t2->data : -1) << endl;
  if (t1 != nullptr && t2 != nullptr) {
    return t1->data == t2->data &&
      is_symmetric_rec(t1->l, t2->r) &&
      is_symmetric_rec(t1->r, t2->l);
  } else if (t1 == nullptr && t2 == nullptr) {
    return true;
  } else {
    return false;
  }
}

bool is_symmetric(const NodePtr& root) {
  if (root == nullptr)
    return true;
  else
    return is_symmetric_rec(root->l, root->r);
}


int main(int argc, char** args) {

  auto tree = node(0,
                   node(1, node(2), node(3)),
                   node(1, node(3), node(2)));

  cout << is_symmetric(tree) << endl;
  
  return 0;
}






