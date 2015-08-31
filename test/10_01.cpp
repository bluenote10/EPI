
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

template<typename ... Args>
string string_format( const char* format, Args ... args )
{
  size_t size = snprintf( nullptr, 0, format, args ... ) + 1; // Extra space for '\0'
  unique_ptr<char[]> buf( new char[ size ] ); 
  snprintf( buf.get(), size, format, args ... );
  return string( buf.get(), buf.get() + size - 1 ); // We don't want the '\0' inside
}


template <typename T>
struct BinaryTree {
  T data;
  unique_ptr<BinaryTree<T>> l, r;

  /*
  BinaryTree(T x) : data(x), l(nullptr), r(nullptr) {};
  BinaryTree(T x, unique_ptr<BinaryTree<T>> l_, unique_ptr<BinaryTree<T>> r_) :
    data(x), l(move(l_)), r(move(r_)) {};
  */
  
  int height() {
    int h_l = (l == nullptr ? 1 : 1 + l->height());
    int h_r = (r == nullptr ? 1 : 1 + r->height());
    //cout << data << " " << h_l << " " << h_r << endl;
    return max(h_l, h_r);
  }

  bool is_balanced_naive() {
    int h_l = (l == nullptr ? 1 : 1 + l->height());
    int h_r = (r == nullptr ? 1 : 1 + r->height());
    bool balanced_l = (l == nullptr ? true : l->is_balanced_naive());
    bool balanced_r = (r == nullptr ? true : r->is_balanced_naive());
    cout << string_format("%d %d %d %d %d\n", data, h_l, h_r, balanced_l, balanced_r);
    return (abs(h_l - h_r) <= 1) && balanced_l && balanced_r;
  }

  bool is_balanced() {
    auto hab = this->height_and_balancedness();
    return hab.first;
  }
  
  pair<int, bool> height_and_balancedness() {
    auto hab_l = (l == nullptr ? make_pair(0,true) : l->height_and_balancedness());
    auto hab_r = (r == nullptr ? make_pair(0,true) : r->height_and_balancedness());
    bool diff_okay = abs(hab_l.first - hab_r.first) <= 1;
    return make_pair(diff_okay && hab_l.second && hab_r.second, 1 + max(hab_l.first, hab_r.first));
  }
};


template <typename T>
unique_ptr<BinaryTree<T>> gen_node(T data, unique_ptr<BinaryTree<T>> l, unique_ptr<BinaryTree<T>> r) {
  unique_ptr<BinaryTree<T>> node{ new BinaryTree<T>{data, move(l), move(r)} };
  //unique_ptr<BinaryTree<T>> node{ new BinaryTree<T>(data, move(l), move(r)) };
  return move(node);
}


int main(int argc, char** args) {

  unique_ptr<BinaryTree<int>> n1 = gen_node<int>(1, nullptr, nullptr);
  unique_ptr<BinaryTree<int>> n2 = gen_node<int>(2, nullptr, nullptr);
  unique_ptr<BinaryTree<int>> n3 = gen_node<int>(3, move(n1), move(n2));
  unique_ptr<BinaryTree<int>> n4 = gen_node<int>(4, nullptr, nullptr);
  unique_ptr<BinaryTree<int>> n5 = gen_node<int>(5, move(n3), move(n4));

  cout << n5->height() << endl;
  cout << n5->is_balanced_naive() << endl;
  cout << n5->is_balanced() << endl;
  
  return 0;
}

