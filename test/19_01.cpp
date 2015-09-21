#include "convenience.hpp"


using uset = unordered_set<int>;
using matrix = vector<vector<bool>>;


int find_celeb(matrix m) {
  int N = m.size();
  uset possible_celebs;
  for (int i=0; i<N; ++i) {
    possible_celebs.insert(i);
  }

  while (possible_celebs.size() > 0) {
    cout << possible_celebs << endl;
    int i = *possible_celebs.cbegin();
    //possible_celebs.erase(i);

    bool i_maybe_celeb = true;

    // check row condition
    for (int j=0; j<N; ++j) {
      if (i != j) {
        if (m[i][j] == false) { // i could still be a celeb, but not j
          possible_celebs.erase(j);
          cout << "discarding (when checking rows) j = " << j << endl;
        } else {
          i_maybe_celeb = false;
          break;
        }
      }
    }
    if (!i_maybe_celeb) {
      cout << "discarding i = " << i << endl;
      possible_celebs.erase(i);
      continue;
    }
    
    // check col condition
    for (int j=0; j<N; ++j) {
      if (i != j) {
        if (m[j][i] == true) { // i could still be a celeb, but not j
          possible_celebs.erase(j);
          cout << "discarding (when checking cols) j = " << j << endl;
        } else {
          i_maybe_celeb = false;
          break;
        }
      }
    }

    if (i_maybe_celeb) {
      return i_maybe_celeb;
    }
  }

  return -1;
}


int main(int argc, char** argv) {

  int N = 10;
  matrix m(N, vector<bool>(N, false));

  int celeb = 3;
  for (int i=0; i<N; ++i) {
    if (i != celeb) m[i][celeb] = true;
  }
  
  cout << m << endl;

  cout << find_celeb(m) << endl;
  
  return 0;
}
