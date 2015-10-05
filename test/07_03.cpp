#include "convenience.hpp"

string convert_to_column(int i, int alphabet_size = 3) {
  if (i <= 0) {
    return "";
  }

  // determine the required size of the block
  int num_digits = 1;
  int max_possible = alphabet_size;
  while (i > max_possible) {
    i -= max_possible;
    max_possible *= alphabet_size;
    num_digits += 1;
  }

  // now we can treat the conversion like a regular base-alphabet_size conversion
  // note that we have to subtract 1 to convert from 1..alphabet_size^k to 0..alphabet_size^k - 1
  // i.e., treating A as a regular "zero"...
  i -= 1;
  string s;
  s.resize(num_digits);
  for (int j=0; j<num_digits; ++j) {
    s[num_digits-1-j] = 'A' + (i % alphabet_size);
    i /= alphabet_size;
  }
  return s;
}


int main(int argc, char** args) {

  for (int i=0; i<100; ++i) {
    cout << i << " " << convert_to_column(i) << endl;
  }

  return 0;
}
