#include "convenience.hpp"

struct Node {
  int data;
  shared_ptr<Node> next;

  Node(int data, shared_ptr<Node> next) : data(data), next(next) {}
};


void reverse(shared_ptr<Node>& node) {

  shared_ptr<Node> prev = nullptr;

  bool finished = false;
  while (!finished) {
    shared_ptr<Node> next = node->next;
    // modify current node
    node->next = prev;
    // store a pointer of current node used in next iteration
    prev = node;
    if (next == nullptr) {
      finished = true;
    } else {
      node = next;
    }
  }
  
}

ostream& operator<<(ostream& o, const shared_ptr<Node>& list) {
  if (list != nullptr) {
    o << list->data << " -> " << list->next;
  } else {
    o << "nullptr";
  }
  return o;
}

int main(int argc, char** args) {

  auto n1 = make_shared<Node>(1, nullptr);
  auto n2 = make_shared<Node>(2, n1);
  auto n3 = make_shared<Node>(3, n2);
  auto n4 = make_shared<Node>(4, n3);

  reverse(n3);
  cout << n3 << endl;
  
  cout << n1.use_count() << endl;
  cout << n2.use_count() << endl;
  cout << n3.use_count() << endl;
  cout << n4.use_count() << endl;
  
  return 0;
}
