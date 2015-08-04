
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

int stringToInt(string s) {
  int res = 0;
  int pos = 1;
  for (int i=s.size()-1; i>=0; --i) {
    int code = int(s[i]);
    if (code >= 48 && code < 58) {
      res += (code - 48) * pos;
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
  
}

int main(int argc, char** argv) {
  cout << "Result: " << stringToInt("909") << endl;
  return 0;
}




