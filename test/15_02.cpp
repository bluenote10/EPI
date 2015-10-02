#include "convenience.hpp"

struct Node;

using NodePtr = unique_ptr<Node>;

struct Node {
  int data;
  NodePtr l, r;
};

NodePtr node(int data, NodePtr l = nullptr, NodePtr r = nullptr) {
  return unique_ptr<Node>(new Node{data, move(l), move(r)});
}



const NodePtr& bin_search(const NodePtr& node, int x) {

  static NodePtr not_found = nullptr;
  
  if (node == nullptr)
    return not_found;

  // we compare against <= because in both cases we have to traverse the left subtree
  else if (x <= node->data) {
    if (node->l != nullptr) {
      const auto& subres = bin_search(node->l, x);
      if (subres != nullptr) {
        return subres;
      } else {
        return (node->data == x ? node : not_found);
      }
    } else {
      return (x == node->data ? node : not_found);
    }
  } else {
    return bin_search(node->r, x);
  }
}


const NodePtr& bin_search_nicer(const NodePtr& node, int x) {

  static NodePtr not_found = nullptr;
  
  if (node == nullptr)
    return not_found;

  else if (x == node->data) {
    // note: this is what breaks tail recursion:
    // if (result_of_recursive_call) ...
    // means that the recursive call is no longer the last operation.
    // It is followed by a comparison + branching.
    const auto& subres = bin_search(node->l, x);
    return (subres != nullptr ? subres : node);
  } else {
    return bin_search((x < node->data ? node->l : node->r), x);
  }
}


Node* bin_search_nonrec(const NodePtr& node, int x) {
  Node* cur = node.get();
  Node* res = nullptr;
  while (cur != nullptr) {
    if (x == cur->data) {
      res = cur;
      cur = cur->l.get();
    } else {
      cur = (x < cur->data ? cur->l.get() : cur->r.get());
    }
  }
  return res;
}



int main(int argc, char** args) {

  auto tree = node(108, node(108, node(-10), node(108)), node(285, node(243), node(285)));

  for (auto find : vector<int>{108, 285, 143}) {
    auto& res1 = bin_search(tree, find);
    auto& res2 = bin_search_nicer(tree, find);
    auto res3 = bin_search_nonrec(tree, find);

    cout << "\nSearch for " << find << endl;    
    cout << (res1 != nullptr ? to_string(res1->data) : "not found") << endl;
    cout << res1.get() << " " << res2.get() << " " << res3 << endl;
  }
  
  return 0;
}


