
#include <iostream>
#include <string>
#include <stdexcept>

// for reverse
#include <algorithm>

using namespace std;

int stringToInt(string s) {
  int res = 0;
  int pos = 1;
  for (int i=s.size()-1; i>=0; --i) {
    char code = s[i];
    if (code >= '0' && code <= '9') {
      res += (code - '0') * pos;
    } else if (s[i] == '-') {
      res *= -1;
      break;
    } else {
      // error
      throw invalid_argument("cannot parse string");
    }
    cout << int(s[i]) << endl;
    pos *= 10;
  }
  return res;
}

string intToString(int x) {
  if (x == 0) return "0";
  string res = "";
  bool isNeg = (x < 0);
  if (isNeg) {
    x = -x;
  }
  while (x > 0) {
    char digit = '0' + (x % 10);
    cout << x << " " << digit << endl;
    res += digit;
    x /= 10;
  }
  if (isNeg) {
    res += '-';
  }
  cout << res << endl;
  reverse(res.begin(), res.end());
  return res;
}

int main(int argc, char** argv) {
  cout << "Result: " << stringToInt("909") << endl;
  cout << "Result: " << intToString(-1234) << endl;
  return 0;
}




