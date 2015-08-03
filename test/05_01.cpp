
#include <iostream>
#include <array>
#include <random>
#include <assert.h>

using namespace std;



int parity1(unsigned long x) {
  int par = 0;
  while (x > 0) {
    if (x & 1 == 1) {
      par ^= 1;
    }
    x >>= 1;
  }
  return par;
}

int parity2(unsigned long x) {
  int par = 0;
  while (x > 0) {
    par ^= 1;
    x = x & (x-1);
  }
  return par;
}

static std::array<int, 65536> lookup;

void initLookup() {
  for (int i = 0; i<65536; i++) {
    lookup[i] = parity2(i);
  }
}

int parity3(unsigned long x) {
  int par = 0;
  //cout << "x = " << x << endl;
  while (x > 0) {
    int block = x & (65536-1);
    par = par ^ lookup[block];
    x >>= 16;
    //cout << x << " " << block << " " << par << endl;
  }
  return par;
}



void check(string test, bool cond) {
  cout << test << " " << cond << endl;
}

template <typename T>
void checkGen(string test, T a, T b) {
  cout << test << ": " << a << " == " << b << (a == b ? " PASSED" : " FAILED") << endl;
}

int main(int argc, char** argv) {
  initLookup();
  
  //check("Test", true);
  auto parity = [](int x) -> int { return parity3(x); };
  checkGen("Parity 1", parity(1), 1);
  checkGen("Parity 1", parity(2), 1);
  checkGen("Parity 3", parity(3), 0);
  checkGen("Parity 7", parity(7), 1);
  checkGen("Parity 24", parity(24), 0);

  for (int i=0; i<10000; i++) {
    unsigned long x = static_cast<long>(rand()) << (sizeof(int) * 8) | rand();
    int p1 = parity1(x);
    int p2 = parity2(x);
    int p3 = parity3(x);
    assert(p1 == p2);
    assert(p2 == p3);
    //int r = rand();
    //int t = r << (sizeof(int)*8);
    //cout << r << " " << t << endl;
  }
  
  return 0;
}

