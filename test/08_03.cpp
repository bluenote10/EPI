#include "convenience.hpp"

struct Node {
  int data;
  shared_ptr<Node> next;

  Node(int data, shared_ptr<Node> next) : data(data), next(next) {}
};

using NodePtr = shared_ptr<Node>;

ostream& operator<<(ostream& o, const shared_ptr<Node>& list) {
  if (list != nullptr) {
    o << list->data << " -> " << list->next;
  } else {
    o << "nullptr";
  }
  return o;
}


NodePtr reverse(shared_ptr<Node>& node, int s, int e) {
  NodePtr to_return = node;
  NodePtr last_regular = nullptr;
  NodePtr to_modify_later = nullptr;
  NodePtr prev = nullptr;
  NodePtr cur = node;
  int i = 1;
  while (cur != nullptr) {
    // back a backup of next
    NodePtr next = cur->next;
    if (i == s-1) {
      last_regular = cur;
    } else if (i == s) {
      to_modify_later = cur;
      cur->next = nullptr; // make it point to null in case we have no trailing elements
    } else if (i > s && i <= e) {
      cur->next = prev;
      if (i == e) {
         if (s == 1) {
           // if the head was involved in the reversal, the e position in the new head to return
           to_return = cur;
         } else {
           // otherwise we must point the last_regular to the e position
           // note that s != 1 implies last_regular != nullptr
           last_regular->next = cur;
         }
      }
    } else if (i == e+1) {
      to_modify_later->next = cur;
    }
    prev = cur;
    cur = next;
    i += 1;
  }
  return to_return;
}


int main(int argc, char** args) {

  auto n4 = make_shared<Node>(4, nullptr);
  auto n3 = make_shared<Node>(3, n4);
  auto n2 = make_shared<Node>(2, n3);
  auto n1 = make_shared<Node>(1, n2);

  cout << n1 << endl;

  auto l = reverse(n1, 3, 4);
  cout << l << endl;

  return 0;
}
