#include "convenience.hpp"

#include <algorithm>

void power_set_rec(const vector<int>& in, vector<int> indices, vector<vector<int>>& results) {
  if (indices.size() == in.size())
    return;

  int first_free_index = (indices.size() > 0 ? indices.back() + 1 : 0);

  for (size_t i = first_free_index; i < in.size(); ++i) {
    indices.push_back(i);

    //results.push_back(indices); // TODO: map to "in"
    vector<int> res;
    transform(indices.begin(), indices.end(), back_inserter(res), [in](int i) { return in[i]; } );
    results.push_back(res);

    power_set_rec(in, indices, results);

    indices.pop_back();
  }
}


vector<vector<int>> power_set(const vector<int>& in) {
  vector<vector<int>> results;
  power_set_rec(in, vector<int>(), results);
  return results;
}


int main(int argc, char** args) {

  auto set = {1,2,3,4,5};

  cout << power_set(set) << endl;

  return 0;
}


