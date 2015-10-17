#include "convenience.hpp"

#include <sstream>
#include <algorithm>

vector<int> get_sunset_view(stringstream& is) {

  vector<int> results;

  int next_height;
  while (is >> next_height) {
    cout << "read: " << next_height << endl;
    while (results.size() > 0 && next_height >= results.back()) {
      results.pop_back();
    }
    results.push_back(next_height);
  }

  reverse(results.begin(), results.end());

  return results;
}


int main(int argc, char** args) {

  vector<int> buildings = {2, 2, 3, 4, 1};

  stringstream ss;
  for (auto it = buildings.crbegin(); it != buildings.crend(); ++it) {
    ss << *it << endl;
  }

  auto result = get_sunset_view(ss);
  cout << result << endl;

}