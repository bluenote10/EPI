#include "convenience.hpp"

#include <unordered_map>

using resmap = unordered_map<int, vector<vector<int>>>;



vector<vector<int>> compute_recursively(const vector<int>& values, int sum, resmap& results, vector<int> path) {
  if (sum == 0) {
    cout << "solution found\n";
    return vector<vector<int>>();
  } else if (sum < 0) {
    cout << "not solvable\n";
    return vector<vector<int>>();
  }
  for (auto v : values) {
    cout << sum-v << " " << path << endl;
    int next_val = sum - v;
    if (results.find(next_val) != results.end()) {
      path.push_back(v);
      auto res = compute_recursively(values, sum-v, results, path);
      results[next_val] = res;
      path.pop_back();
    }
    auto next_results = results[next_val];
    for (auto& result : next_results) {
      for (auto p : path) {
        result.push_back(p);
      }
    }
    cout << next_results << endl;
  }
  return vector<vector<int>>();
}


void compute_combinations1(const vector<int>& allowed_scores, int sum) {
  vector<int> scores(sum+1, 0);
  scores[0] = 1;
  for (int i=0; i<=sum; ++i) {
    for (int j=0; j<allowed_scores.size(); ++j) {
      int below = i - allowed_scores[j];
      if (below >= 0) {
        scores[i] = scores[i] + scores[below];
      }
      cout << i << " " << below << " " << scores[i] << endl;
    }
  }
  cout << scores << endl;
}

void compute_combinations2(const vector<int>& allowed_scores, int sum) {
  vector<int> scores(sum+1, 0);
  scores[0] = 1;
  for (int j=0; j<allowed_scores.size(); ++j) {
    for (int i=0; i<=sum; ++i) {
      int below = i - allowed_scores[j];
      if (below >= 0) {
        scores[i] = scores[i] + scores[below];
      }
      cout << i << " " << below << " " << scores[i] << endl;
    }
  }
  cout << scores << endl;
}



int main(int argc, char** argv) {

  vector<int> values = {2,3,7};

  compute_combinations2(values, 20);
  
  return 0;
}



