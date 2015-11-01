#include "convenience.hpp"


void Blockify(vector<int>& A, int max_idx) {

    if (max_idx <= 0) return;

    int pivot = A[0];
    A[max_idx] = A[0];

    int i = 0;
    int j = max_idx - 1;

    int k = 1;
    while (i < j) {
        cout << A << " " << i << " " << j << " " << k << endl;
        if (A[k] != pivot) {
            swap(A[i++], A[k++]);
        } else {
            swap(A[j--], A[k]);
        }
    }

    Blockify(A, j);
}


int main(int argc, char** args) {

    vector<int> v = {2, 1, 2, 2, 1, 2, 1, 1};

    Blockify(v, v.size()-1);

    cout << v << endl;

    return 0;
}
