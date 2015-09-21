
#include <list>
#include <iterator>
#include <memory>

#include "convenience.hpp"





template <typename T>
struct Node {
  T data;
  unique_ptr<Node<T>> left, right;
};

/*

        5
       / \
      3   4
     / \
    1   2
  
 */

template <typename T>
unique_ptr<Node<T>> new_node(const T& data, unique_ptr<Node<T>> left = nullptr, unique_ptr<Node<T>> right = nullptr) {
  return unique_ptr<Node<int>>(new Node<int>{data, move(left), move(right)});
}

void test() {
  unique_ptr<Node<int>> n1(new Node<int>{1, nullptr, nullptr});
  unique_ptr<Node<int>> n2(new Node<int>{2, nullptr, nullptr});
  unique_ptr<Node<int>> n3(new Node<int>{3, move(n1), move(n2)});
  unique_ptr<Node<int>> n4(new Node<int>{4, nullptr, nullptr});
  unique_ptr<Node<int>> root(new Node<int>{5, move(n3), move(n4)});

  unique_ptr<Node<int>> root2(new Node<int>{5,
    unique_ptr<Node<int>>(new Node<int>{3,
      unique_ptr<Node<int>>(new Node<int>{1, nullptr, nullptr}),
      unique_ptr<Node<int>>(new Node<int>{2, nullptr, nullptr})
    }),
    unique_ptr<Node<int>>(new Node<int>{4, nullptr, nullptr})
  });

  auto root3 =
    new_node(4,
      new_node(3,
        new_node(1),
        new_node(2)),
      new_node(5)
    );

  cout << "here" << root3-> data << endl;
}








template <typename T>
struct BSTNode {
  T data;
  unique_ptr<BSTNode<T>> l, r;
};

template <typename T>
using NodePtr = unique_ptr<BSTNode<T>>;

template <typename T>
unique_ptr<BSTNode<T>> node(const T& data,
                            unique_ptr<BSTNode<T>> l = nullptr,
                            unique_ptr<BSTNode<T>> r = nullptr) {
  return unique_ptr<BSTNode<T>>(new BSTNode<T>{data, move(l), move(r)});
}


template <typename T>
bool check_BST_property_nonrec(const BSTNode<T>& node) {

  // TODO
  BSTNode<T> const* cur = &node;
  cout << cur->data << endl;

  if (cur->l != nullptr) {
    cur = cur->l.get();
    cout << cur->data << endl;
  }
  
  return true;
}




template <typename T>
void traverse(const NodePtr<T>& node, list<T>& l, typename list<T>::iterator& it) {
  if (node->l != nullptr) {
    traverse(node->l, l, it);
  }
  it = l.emplace(it, node->data);
  it++;
  if (node->r != nullptr) {
    traverse(node->r, l, it);
  }
}

template <typename T>
bool check_BST_property_by_traverse(const NodePtr<T>& node) {

  list<int> data;
  list<int>::iterator it = data.begin();

  traverse(node, data, it);

  cout << data << endl;

  auto it1 = data.cbegin();
  auto it2 = data.cbegin(); it2++;

  while (it2 != data.cend()) {
    cout << *it1 << " " << *it2 << endl;
    if (*it1 > *it2) return false;
    it1++; it2++;
  }
  
  return true;
}


template <typename T>
T min3(const T& a, const T& b, const T& c) {
  return min(min(a, b), c);
}
template <typename T>
T max3(const T& a, const T& b, const T& c) {
  return max(max(a, b), c);
}

template <typename T>
tuple<T, T, bool> check_BST_recursion(const NodePtr<T>& node) {
  if (node->l != nullptr && node->r != nullptr) {
    auto result_l = check_BST_recursion(node->l);
    auto result_r = check_BST_recursion(node->r);
    T min_l, max_l, min_r, max_r;
    bool okay_l, okay_r;
    tie(min_l, max_l, okay_l) = result_l;
    tie(min_r, max_r, okay_r) = result_r;
    if (!okay_l) return make_tuple(T(), T(), false);
    if (!okay_r) return make_tuple(T(), T(), false);
    if (max_l > node->data) return make_tuple(T(), T(), false);
    if (min_r < node->data) return make_tuple(T(), T(), false);
    cout << vector<T>{min_l, max_l, min_r, max_r} << endl;
    return make_tuple(min3(min_l, min_r, node->data),
                      max3(max_l, max_r, node->data),
                      true);
  } else if (node->l != nullptr) {
    auto result_l = check_BST_recursion(node->l);
    T min_l, max_l;
    bool okay_l;
    tie(min_l, max_l, okay_l) = result_l;
    if (!okay_l) return make_tuple(T(), T(), false);
    if (max_l > node->data) return make_tuple(T(), T(), false);
    cout << vector<T>{min_l, max_l} << endl;
    return make_tuple(min(min_l, node->data),
                      max(max_l, node->data),
                      true);
  } else if (node->r != nullptr) {
    auto result_r = check_BST_recursion(node->r);
    T min_r, max_r;
    bool okay_r;
    tie(min_r, max_r, okay_r) = result_r;
    if (!okay_r) return make_tuple(T(), T(), false);
    if (max_r < node->data) return make_tuple(T(), T(), false);
    cout << vector<T>{min_r, max_r} << endl;
    return make_tuple(min(min_r, node->data),
                      max(max_r, node->data),
                      true);
  } else {
    cout << "leaf " << node->data << endl;
    return make_tuple(node->data, node->data, true);
  }
}

template <typename T>
bool check_BST_property(const NodePtr<T>& node) {

  auto result_at_root = check_BST_recursion(node);
  
  return get<2>(result_at_root);
}




int main(int argc, char** args) {

  //test();

  auto root = node(4,
                   node(3, node(1), node(8)),
                   node(9)
                   );
  
  cout << (check_BST_property(root) ? "true" : "false") << endl;
  
  return 0;
}






