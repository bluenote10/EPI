#include "convenience.hpp"


vector<int>& merge_sort(vector<int>& v1, const vector<int>& v2) {

  int i = v1.size() - 1;
  int j = v2.size() - 1;

  v1.resize(v1.size() + v2.size());
  
  while (i >= 0) {
    cout << i << " " << j << endl;
    while (j >= 0 && v2[j] > v1[i]) {
      v1[i+j+1] = v2[j];
      cout << v1 << " after adding from j = " << j << endl;
      --j;
    }
    v1[i+j+1] = v1[i];
    cout << v1 << " after adding from i = " << i << endl;
    --i;
  }

  while (j >= 0) {
    v1[i+j+1] = v2[j];
    cout << v1 << " after adding from j = " << j << endl;
    --j;
  }
  
  return v1;
}


int main(int argc, char** args) {

  vector<int> v1{5, 13, 17};
  vector<int> v2{3, 7, 11, 19};
  
  cout << merge_sort(v1, v2) << endl;
  
  return 0;
}


