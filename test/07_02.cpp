#include "convenience.hpp"

#include <algorithm>

int char_to_int(char c) {
  int t = c - '0';
  if (t > 9)
    t = 10 + c - 'A';
  return t;
}
char int_to_char(int x) {
  if (x < 10)
    return '0' + x;
  else
    return 'A' - 10 + x;
}


string convert(string s, int b1, int b2) {
  reverse(s.begin(), s.end());

  int base;

  int x = 0;
  base = 1;
  for (int i=0; i<s.size(); i++) {
    int digit = char_to_int(s[i]);
    x += digit * base;
    base *= b1;
  }


  base = 1;
  while (base * b2 <= x) {
    base *= b2;
  }
  cout << base << endl;

  string result;
  while (base != 0) {
    int digit = x / base;
    x = x % base;
    result.push_back(int_to_char(digit));
    base /= b2;
  }
  
  return result;
  
}


int main(int argc, char** args) {

  cout << convert("11A", 16, 3) << endl;
  
  return 0;
}
