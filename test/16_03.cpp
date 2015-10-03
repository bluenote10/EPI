#include "convenience.hpp"


vector<vector<int>> permutations(const vector<int>& in) {
  if (in.size() <= 1)
    return vector<vector<int>>{in};
  else {
    // build "tail" -- rather the reverse-tail for performance reasons
    auto tail = in;
    tail.erase(tail.end() - 1);

    // get permutations of the tail
    auto perms = permutations(tail);

    // build results by inserting in.back() at all possible positions
    vector<vector<int>> result;
    for (const auto& p : perms) {
      for (size_t j=0; j<p.size()+1; ++j) { // note: "all possible" includes the size+1 index
        auto modified_p = p;
        modified_p.insert(modified_p.begin() + j, in.back());
        result.push_back(modified_p);
      }
    }
    return result;
  }
}



void permutations_rec(size_t i, vector<int>& v, vector<vector<int>>& results) {
  if (i == v.size()-1) {
    results.push_back(v);
    return;
  } else {
    for (size_t j=i; j<v.size(); ++j) {
      swap(v[i], v[j]);
      permutations_rec(i+1, v, results);
      swap(v[i], v[j]);
    }
  }
}

vector<vector<int>> permutations_efficient(vector<int> v) {
  vector<vector<int>> results;
  permutations_rec(0, v, results);
  return results;
}



int main(int argc, char** args) {

  vector<int> data = {1,2,3,4};
  cout << permutations(data) << endl;
  cout << permutations_efficient(data) << endl;
  
  return 0;
}


