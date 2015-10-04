#include "convenience.hpp"

bool test_traversable(vector<int> steps) {

  vector<bool> reached(steps.size(), false);
  reached[0] = true;

  int i = 0;
  while (i < steps.size() && reached[i] == true) {
    for (int j=i+1; j<i+1+steps[i] && j < steps.size(); ++j) {
      reached[j] = true;
      cout << "from " << i << ": " << j << " is reachable\n";
    }
    i++;
    cout << i << " " << reached << endl;
  }

  return reached[steps.size()-1];
}

bool test_traversable2(vector<int> steps) {

  int max_reached = 0;

  int i = 0;
  while (i <= max_reached && i < steps.size()) {
    max_reached = max(max_reached, i + steps[i]);
    cout << "from " << i << ": " << max_reached << " is reachable\n";
    i++;
  }

  return max_reached >= steps.size(); // note: we have to point behind the last element
}

int main(int argc, char** args) {

  auto test1 = {3, 3, 1, 0, 2, 0, 1};
  auto test2 = {3, 2, 0, 0, 2, 0, 1};

  cout << test_traversable2(test1) << endl;
  cout << test_traversable2(test2) << endl;

  return 0;
}
