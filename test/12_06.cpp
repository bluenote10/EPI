#include "convenience.hpp"


double pseudo_sqrt1(double x) {
  double l = min(1.0, x);
  double h = max(1.0, x);
  while (h-l > 0.0001) {
    double mid = (h+l) / 2;
    double mid_squared = mid * mid;
    cout << l << " " << h << " mid = " << mid << " " << mid_squared << endl;
    if (mid_squared > x) {
      h = mid;
    } else {
      l = mid;
    }
  }
  return (h+l) / 2;
}

double pseudo_sqrt2(double x) {
  double l = min(1.0, x);
  double h = max(1.0, x);
  double l_squared = l * l;
  double h_squared = h * h;
  while (h-l > 0.0001) {
    double dx = h - l;
    double dy = h_squared - l_squared;
    double ratio = (x - l_squared) / dy;
    ratio = (ratio + 0.5) / 2;
    double mid = l + (ratio * dx);
    double mid_squared = mid * mid;
    cout << l << " " << h << " mid = " << mid << " " << mid_squared << endl;
    if (mid_squared > x) {
      h = mid;
      h_squared = mid_squared;
    } else {
      l = mid;
      l_squared = mid_squared;
    }
  }
  return (h+l) / 2;
}


int main(int argc, char** agrs) {

  //cout << pseudo_sqrt2(2) << endl;

  auto x = 1000;
  cout << pseudo_sqrt1(x) << endl;
  cout << pseudo_sqrt2(x) << endl;
  
  return 0;
}
