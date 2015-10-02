#ifndef CONVENIENCE
#define CONVENIENCE

#include <iostream>
#include <vector>
#include <list>
#include <memory>
#include <unordered_set>
#include <unordered_map>

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

template <typename T>
ostream& operator<<(ostream& os, const list<T>& l) {
  os << "[";
  auto i = 0;
  auto it = l.cbegin();
  while (it != l.cend()) {
    if (i != 0) os << ", ";
    os << *it;
    ++it; ++i;
  }
  os << "]";
  return os;
}

template <typename T>
ostream& operator<<(ostream& os, const unordered_set<T>& s) {
  os << "[";
  auto i = 0;
  auto it = s.cbegin();
  while (it != s.cend()) {
    if (i != 0) os << ", ";
    os << *it;
    ++it; ++i;
  }
  os << "]";
  return os;
}

template <typename T, typename U>
ostream& operator<<(ostream& os, const unordered_map<T, U>& m) {
  os << "[";
  auto i = 0;
  auto it = m.cbegin();
  while (it != m.cend()) {
    if (i != 0) os << ", ";
    os << it->first << " -> " << it->second;
    ++it; ++i;
  }
  os << "]";
  return os;
}


template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T,U>& pair) {
  os << "<" << pair.first << ", " << pair.second << ">";
  return os;
}



template<typename T, typename ...Args>
unique_ptr<T> make_unique( Args&& ...args )
{
    return std::unique_ptr<T>( new T( std::forward<Args>(args)... ) );
}




#endif
