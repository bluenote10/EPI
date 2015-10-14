
// -----------------------
// General Reminders
// -----------------------

// how much space does it require to represent an integer as a single bit,
// corresponding to a "number on a line" (e.g. for storing a set of ints)?
// 16 bit int, values 0..65000 => bit set has size 8k
// 32 bit int, values 0..4294967296 = 4.2 * 10^9 => bit set has 512 MB
// a reasonable range would be 0..10 million which has bit set size ~1 MB
// question inspired from: http://alexbowe.com/rrr/

// complexity of storing permutations?
// O(N * N!) because the number of permutations itself is N!
// but storing each permutation itself is O(N)


// clear the lowest set bit of x
x & (x - 1)

// extract the lowest set bit of x
x & ~(x - 1)

// swap bit i
x ^ (1L << i)

// simple argument why quicksort/quickselect are worst case quadratic
// => triangular numbers grow quadratically


// -----------------------
// C++ specific
// -----------------------


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



