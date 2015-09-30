
// clear the lowest set bit of x
x & (x - 1)

// extract the lowest set bit of x
x & ~(x - 1)

// swap bit i
x ^ (1L << i)


// determine extreme values of a type T
#include <limits>
int best_val = std::numeric_limits<int>::max();


// negative vector indices:
v[i]    // no bounds check and negative allowed (but relative to start, not relative to end, think pointers not python)
v.at(i) // with bounds check and negative always throw out_of_range


// split a string
vector<string> split(const string& s, char delim) {
  vector<string> result;
  stringstream ss(s);
  string item;
  while (getline(ss, item, delim)) {
    result.push_back(item);
  }
  return result;
}

// convert a string to float _and_ validate it (atof will return 0.0 on errors :())
istringstream iss(s);
double value;
iss >> ws >> value >> ws; // ws for allowing surrounding white space
if (iss.eof() && !iss.fail()) {
  // okay
}



