#include "convenience.hpp"

#include <algorithm>

vector<int> next_perm(vector<int> perm) {

  int i = perm.size() - 1;
  while (i > 0 && perm[i-1] > perm[i]) {
    --i;
  }

  if (i == 0) {
    return vector<int>();
  }

  int pivot_idx = i - 1;
  int pivot_val = perm[pivot_idx];

  int smallest_larger_idx = -1;
  int smallest_larger_val = -1;
  for (int i = pivot_idx + 1; i < perm.size(); ++i) {
    if (perm[i] > pivot_val && (smallest_larger_idx == -1 || perm[i] < smallest_larger_val)) {
      smallest_larger_idx = i;
      smallest_larger_val = perm[i];
    }
  }

  swap(perm[pivot_idx], perm[smallest_larger_idx]);

  reverse(perm.begin() + pivot_idx + 1, perm.end());

  return perm;
}


int main(int argc, char** args) {

  vector<int> p = {1, 2, 3, 4};

  do {
    cout << p << endl;
    p = next_perm(p);
  } while (p.size() != 0);

  return 0;

}
