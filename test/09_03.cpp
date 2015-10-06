#include "convenience.hpp"


/*
Since there was no negative example like ([)(]), let's assume this is valid as well.

... okay the negative examples gave a wrong hint.
*/
bool is_valid(string s) {
  int c1 = 0, c2 = 0, c3 = 0; // man, C++ sucks, int c1, c2, c3 = 0 does not intialize all at once :(
  for (const auto& c : s) {
    if      (c == '(') ++c1;
    else if (c == ')') --c1;
    else if (c == '[') ++c2;
    else if (c == ']') --c2;
    else if (c == '{') ++c3;
    else if (c == '}') --c3;
    if (c1 < 0 || c2 < 0 || c3 << 0) return false;
  }
  cout << c1 << " " << c2 << " " << c3 << endl;
  return c1 == 0 && c2 == 0 && c3 == 0;
}


int main(int argc, char** args) {

  cout << is_valid("([{}]))(") << endl;

  return 0;
}
