
#include "convenience.hpp"


int find_first_naive(const vector<int>& data, int key) {
  int l = 0;
  int u = data.size()-1;

  int mid_ind = -1;
  
  while (u >= l) {
    mid_ind = l + (u-l)/2;
    int mid_val = data[mid_ind];
    cout << l << " " << mid_ind << " " << mid_val << " " << u << endl;
    if (key < mid_val) {
      u = mid_ind - 1;
    } else if (key > mid_val) {
      l = mid_ind + 1;
    } else {
      break;
    }
  }

  while (mid_ind > 0) {
    if (data[mid_ind-1] == key) {
      cout << "decreasing " << mid_ind << endl;
      mid_ind--;
    } else {
      break;
    }
  }

  return mid_ind;
}


int find_first(const vector<int>& data, int key) {

  // implemented as "first >=" with final equality check
  // using half-open range 

  int l = 0; // inclusive
  int u = data.size(); // exclusive, current best-so-far

  while (u > l) {
    int mid_ind = l + (u-l)/2;
    int mid_val = data[mid_ind];
    cout << l << " " << mid_ind << " " << mid_val << " " << u << endl;
    if (mid_val >= key) { // this determines "first >=", change to ">" to get "first >"
      u = mid_ind; // update best-so-far
    } else {
      l = mid_ind + 1;
    }
  }
  
  cout << l << " " << u << endl;
  // if u has never be updated => key was larger than anything, no "first >="
  if (u == data.size())
    return -1;
  // if we have a valid u, it can either be "first >" or "first =="
  else if (data[u] != key)
    return -1; // it was "first >", no equal element at all
  else
    return u;  // it was "first =="
}


int main(int argc, char** args) {

  vector<int> data = {-14, -10, 2, 108, 108, 243, 285, 285, 285, 401};

  cout << find_first(data, -500) << endl;
  
  return 0;
}

