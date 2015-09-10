#ifndef CONVENIENCE
#define CONVENIENCE

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vec) {
  os << "[";
  for (int i=0; i<vec.size(); i++) {
    if (i != 0) os << ", ";
    os << vec[i];
  }
  os << "]";
  return os;
}

template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T,U>& pair) {
  os << "<" << pair.first << ", " << pair.second << ">";
  return os;
}




#endif
