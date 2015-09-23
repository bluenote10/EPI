#include "convenience.hpp"

#include <algorithm>


void normalize(vector<int>& x) {
  int overflow = 0;
  for (size_t i=0; i<x.size(); i++) {
    int sum = x[i] + overflow;
    x[i] = sum % 10;
    overflow = sum / 10;
    //cout << overflow << endl;
  }
  while (overflow > 0) {
    x.push_back(overflow % 10);
    overflow /= 10;
  }
}


vector<int> operator*(vector<int> lhs, vector<int> rhs) {

  // TODO: assert at least 1 digit
  bool positive = lhs[0] * rhs[0] > 0;

  // to simplify things we reverse the vecs (that's also why we take them by value)
  reverse(lhs.begin(), lhs.end());
  reverse(rhs.begin(), rhs.end());
  
  vector<int> result;
  for (size_t i=0; i<lhs.size(); i++) {
    for (size_t j=0; j<rhs.size(); j++) {
      int index = i + j;
      int value = abs(lhs[i]) * abs(rhs[j]);
      //cout << lhs[i] << " " << rhs[j] << " " << index << " " << value << endl;
      if (index >= result.size()) {
        result.push_back(value);
      } else {
        result[index] += value;
      }
    }
    // deal with overflows, it is paranoid to do it in every iteration, could be relaxed later
    cout << result << endl;
    normalize(result);
    cout << result << endl;
  }

  // reverse and fix sign
  reverse(result.begin(), result.end());
  if (!positive) {
    result[0] = -result[0];
  }
  
  return result;
}

int main(int argc, char** args) {

  vector<int> z = {9999, 99, 99, 99};
  normalize(z);
  cout << z << endl;

  vector<int> x = {1, 9, 3, 7, 0, 7, 7, 2, 1};
  vector<int> y = {-7, 6, 1, 8, 3, 8, 2, 5, 7, 2, 8, 7};
  cout << x * y << endl;
  
  return 0;
}


