#include "convenience.hpp"

#include <sstream>

vector<string> split(const string& s, char delim) {
  vector<string> result;
  stringstream ss(s);
  string item;
  while (getline(ss, item, delim)) {
    result.push_back(item);
  }
  return result;
}


double evaluate_rpn(const string& s) {
  auto fields = split(s, ',');
  cout << fields << endl;

  vector<double> stack;

  for (const auto& f : fields) {
    istringstream iss(f);
    double value;
    iss >> ws >> value >> ws;
    if (iss.eof() && !iss.fail()) {
      cout << f << " is a value\n";
      stack.push_back(value);
    } else if (stack.size() == 2) {
      cout << "applying operator " << f << endl;
      if (f == "+") { // well, we should strip WS, but okay...
        stack[0] = stack[0] + stack[1];
      } else if (f == "-") {
        stack[0] = stack[0] - stack[1];
      } else if (f == "*") {
        stack[0] = stack[0] * stack[1];
      } else if (f == "/") {
        stack[0] = stack[0] / stack[1];
      }
      stack.pop_back();
    }
    cout << stack << endl;
  }
  
  return stack.front();
}


int main(int argc, char** args) {

  auto expr = "1,1,+,4,*,3,/,2,-";
  evaluate_rpn(expr);
  
  return 0;
}





