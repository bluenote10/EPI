
#include "convenience.hpp"


vector<int> intersect(const vector<int>& v1, const vector<int>& v2) {
  cout << v1 << endl << v2 << endl;
  vector<int> out;

  auto i1 = v1.cbegin();
  auto i2 = v2.cbegin();

  int last = 0;
  
  while (i1 != v1.cend() && i2 != v2.cend()) {
    cout << *i1 << " " << *i2 << endl;
    if (*i1 == *i2) {
      if (out.size() == 0 || *i1 != last) {
        out.push_back(*i1);
        last = *i1;
      }
      i1++;
      i2++;
    } else {
      if (*i1 < *i2) {
        i1++;
      } else {
        i2++;
      }
    }
  }
  
  return out;
}


int main(int argc, char** args) {

  vector<int> v1{2, 3, 3, 5, 5, 6, 7, 7, 8, 12};
  vector<int> v2{5, 5, 6, 8, 8, 9, 10, 10};

  cout << intersect(v1, v2) << endl;
  
  return 0;
}
