#include "convenience.hpp"

#include <algorithm>

vector<pair<int,int>> Union(vector<pair<int,int>> ints) {
  if (ints.size() == 0) return vector<pair<int,int>>();

  sort(ints.begin(), ints.end());

  vector<pair<int,int>> results;

  int cur_start = ints[0].first;
  int cur_end = ints[0].second;
  int i = 1;

  while (i < ints.size()) {
    if (ints[i].first > cur_end) {
      results.push_back(make_pair(cur_start, cur_end));
      cur_start = ints[i].first;
      cur_end = ints[i].second;
    } else {
      cur_end = max(cur_end, ints[i].second);
    }
    ++i;
  }
  // insert remaining
  results.push_back(make_pair(cur_start, cur_end));

  return results;
}

int main(int argc, char** args) {
  vector<pair<int,int>> ints = {{1,5}, {3,3}, {4,4}};

  auto result = Union(ints);

  cout << result << endl;

  return 0;
}
