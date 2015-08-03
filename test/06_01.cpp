
#include <iostream>
#include <vector>


using namespace std;


template <typename T>
void swap(vector<T> &data, int i, int j) {
  T tmp = data[i];
  data[i] = data[j];
  data[j] = tmp;
}

template <typename T>
void dutchInPlace(vector<T> &data, T pivot) {

  int indexL = 0;
  int indexR = data.size() - 1;

  int i = 0;
  while (i <= indexR) {
    cout << i << " " << data[i] << "\n";
    if (data[i] < pivot) {
      data[indexL] = data[i];
      indexL++;
      i++;
    } else if (data[i] > pivot) {
      swap(data, i, indexR);
      indexR--;
    } else {
      i++;
    }
  }
  for (int i=indexL; i<=indexR; i++) {
    data[i] = pivot;
  }
  cout << indexL << endl;
  cout << indexR << endl;
}


int main(int argc, char** args) {
  auto v = vector<int>{3,1,2,3,1,2,3,1,2,3,1};
  //auto v = vector<int>{3,3,3};
  dutchInPlace(v, 2);

  cout << "Output:\n";
  for (auto element: v)
    cout << element << endl;
}

