#include "convenience.hpp"


unsigned long swap_bit(unsigned long x, int i, int j) {

  if (((x >> i) & 1) == ((x >> j) & 1))
    return x;

  unsigned long mask = (1L << i) | (1L << j);
  
  return x ^ mask;
}


int main(int argc, char** args) {

  unsigned long x = 23;

  x = swap_bit(x, 0, 1);
  
  cout << x << endl;
  
  return 0;
}


