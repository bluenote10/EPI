
#include <iostream>
#include <vector>

using namespace std;

void addOne(vector<int> &number) {
  // we can achieve the "+1" by initializing with
  // an overflow of 1
  int overflow = 1;
  for (int i=number.size()-1; i>=0; --i) {
    int digit = number[i];
    number[i] = (digit + overflow) % 10;
    overflow = (digit + overflow) / 10;
    if (overflow == 0) break;
  }
  if (overflow > 0) {
    number.insert(number.begin(), overflow);
  }
}


int main(int argc, char** argv) {

  auto number = vector<int>{1,0,0};

  addOne(number);

  cout << "Result:\n";
  for (auto el: number) {
    cout << el << endl;
  }

  return 0;
}

