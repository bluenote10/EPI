#include "convenience.hpp"


int first_larger_than(vector<int> data, int k) {
  int l = 0;
  int h = data.size();

  while (h > l) {
    int mid = l + (h - l)/2;
    cout << l << " " << mid << " " << h << endl;
    if (data[mid] > k) {
      h = mid;
    } else {
      l = mid + 1;
    }
  }

  if (h == data.size()) return -1; else return h;
}


int first_larger_than_inclusive(vector<int> data, int k) {
  int l = 0;
  int h = data.size()-1;
  int result = -1;
  
  while (l <= h) {
    int mid = l + (h - l)/2;
    cout << l << " " << mid << " " << h << endl;
    if (data[mid] > k) {
      result = mid;
      h = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return result;
}



int main(int argc, char** args) {

  vector<int> data = {1,1,1,2,2,2,3,3,3};

  cout << first_larger_than_inclusive(data, 3) << endl;

  return 0;
}



