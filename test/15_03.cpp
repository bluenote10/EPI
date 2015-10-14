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



Node* findFirstLargerThan(const NodePtr& n, int val) {
  Node* res = nullptr;
  Node* cur = n.get();
  while (cur != nullptr) {
    if (val < cur->data) {
      // the node fulfills "larger than", so we store it
      // but the left subtree may still contain a value larger than val
      // which is before the current node in an inorder traversal
      res = cur;
      cur = cur->l.get();
    } else {
      cur = cur->r.get();
    }
  }
  return res;
}


int main(int argc, char** args) {



  return 0;
}


