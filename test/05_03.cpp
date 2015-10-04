#include "convenience.hpp"


unsigned long reverse(unsigned long x) {
  unsigned long flipmask = 0L;
  for (unsigned long l = 0; l<32; ++l) {
    unsigned long h = 63 - l;
    if (((x >> l) & 1L) != ((x >> h) & 1L)) {
      flipmask |= (1L << l) | (1L << h);
    }
  }
  cout << flipmask << endl;
  return x ^ flipmask;
}


int main(int argc, char** args) {

  cout << reverse(127) << endl;

  return 0;
}
