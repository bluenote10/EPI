#include "convenience.hpp"

#include <limits>
#include <algorithm>

int calc_score(const vector<int>& v) {
  int max = numeric_limits<int>::min();
  for (size_t i=0; i<v.size()-1; i+=2) {
    int sum = v[i] + v[i+1];
    if (sum > max)
      max = sum;
  }
  return max;
}

void group_tasks_rec(vector<int>& v, size_t i, int& best_score, vector<int>& best) {
  if (i >= v.size() - 2) {
    int score = calc_score(v);
    cout << v << " has score " << score << endl;
    if (score < best_score) {
      best_score = score;
      best = v;
      cout << " ... which is a new best\n";
    }
    return;
  }
  for (size_t j=i; j<v.size(); ++j) {
    for (size_t k=j+1; k<v.size(); ++k) {
      // swap v[j] and v[k] to the first two positions
      swap(v[i], v[j]);
      swap(v[i+1], v[k]);
      cout << i << " " << j << " " << k << " " << v << endl;
      group_tasks_rec(v, i+2, best_score, best);
      swap(v[i], v[j]);
      swap(v[i+1], v[k]);
    }
  }
}

vector<int> group_tasks(vector<int> durations) {
  vector<int> best;
  int best_score = numeric_limits<int>::max();
  group_tasks_rec(durations, 0, best_score, best);
  return best;
}

// this actually should work...
vector<int> group_tasks_heuristic(vector<int> durations) {
  vector<int> best(durations.size());
  sort(durations.begin(), durations.end());
  for (size_t i=0; i<durations.size()/2; ++i) {
    best[2*i]   = durations[i];
    best[2*i+1] = durations[durations.size()-i-1];
  }
  return best;
}




int main(int argc, char** args) {

  auto durations =
    // {4, 1, 6, 2, 4, 5};
    // {5, 2, 1, 6, 4, 4};
    {1,2,2,5};

  cout << group_tasks(durations) << endl;
  cout << group_tasks_heuristic(durations) << endl;
  
  return 0;
}


