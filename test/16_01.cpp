
#include <iostream>
#include <vector>
#include <iterator>

#include <cassert>

using namespace std;



int determine_temp(int a, int b) {
  if (a == 0 && b == 1) return 2;
  if (a == 1 && b == 0) return 2;
  if (a == 0 && b == 2) return 1;
  if (a == 2 && b == 0) return 1;
  if (a == 1 && b == 2) return 0;
  if (a == 2 && b == 1) return 0;
}


class Hanoi {

private:
  vector<int> stacks[3] = {{5,4,3,2,1}, {}, {}};
  
public:
  void move(int from, int to) {
    assert(stacks[from].size() > 0);
    assert((stacks[to].size() == 0) || (stacks[to].back() > stacks[from].back()));
    stacks[to].push_back(stacks[from].back());
    stacks[from].pop_back();
    cout << "after moving " << from << " to " << to << ": ";
    this->print();
  }


  void move_tower(int size, int from, int to) {
    if (size == 1) {
      this->move(from, to);
    } else {
      int temp = determine_temp(from, to);
      move_tower(size-1, from, temp);
      move(from, to);
      move_tower(size-1, temp, to);
    }
  }
  
  void print() {
    cout << "L: [";
    copy(stacks[0].begin(), stacks[0].end(), ostream_iterator<int>(cout, " "));
    cout << "] M: [";
    copy(stacks[1].begin(), stacks[1].end(), ostream_iterator<int>(cout, " "));
    cout << "] R: [";
    copy(stacks[2].begin(), stacks[2].end(), ostream_iterator<int>(cout, " "));
    cout << "]" << endl;
  }
};


int main(int argc, char** args) {

  Hanoi hanoi;

  hanoi.print();
  hanoi.move_tower(5, 0, 1);
  
  return 0;
}

