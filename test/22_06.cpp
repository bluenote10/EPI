#include "convenience.hpp"

void rotate(vector<int>& A, int i) {
  int N = A.size();

  int ow_idx = 0;
  int val_backup;
  int val_next = A[(A.size() - i) % N];

  int n = 0;
  while (n < N) {
    cout << ow_idx << " " << val_next << " " << val_backup << endl;
    val_backup = A[ow_idx];
    A[ow_idx] = val_next;
    ow_idx = (ow_idx + i) % N;
    val_next = val_backup;
    n++;
  }
}


int main(int argc, char** args) {
  vector<int> A{2, 1, 4, 5, 3};

  rotate(A, 5);

  cout << A << endl;

  return 0;
}
