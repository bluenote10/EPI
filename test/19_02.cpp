#include "convenience.hpp"


bool test_reachability(const vector<vector<bool>>& walkable) {

  int N = walkable.size();
  int M = walkable[0].size();
  vector<vector<bool>> reached(N, vector<bool>(M, false));
  vector<vector<bool>> processed(N, vector<bool>(M, false));

  auto is_reached = [N, M, &reached](int i, int j) -> bool {
    if (i < 0 || j < 0 || i >= N || j >= M) {
      return false;
    } else {
      return reached[i][j];
    }
  };

  auto is_processed = [N, M, &processed](int i, int j) -> bool {
    if (i < 0 || j < 0 || i >= N || j >= M) {
      return true;
    } else {
      return processed[i][j];
    }
  };

  vector<pair<int,int>> stack;

  reached[0][0] = true;
  processed[0][0] = true;
  stack.push_back({0, 0});

  while (stack.size() > 0) {
    auto cur = stack.back();
    stack.pop_back();

    auto neighbors = {make_pair( 0,+1), make_pair(-1, 0), make_pair(+1, 0), make_pair( 0,-1)};

    for (const auto& n : neighbors) {
      int i = cur.first + n.first;
      int j = cur.second + n.second;
      if (!is_processed(i, j)) {
        if (walkable[i][j]) {
          reached[i][j] = true;
          stack.push_back({i, j});
        }
        processed[i][j] = true;
      }
    }
    cout << "after processing " << cur.first << " " << cur.second << endl;
    cout << processed << endl;
    cout << reached << endl;
    cout << stack << endl;

  }

  return reached[N-1][M-1];
}


int main(int argc, char** args) {

  vector<vector<bool>> walkable = {
    {1, 1, 1},
    {0, 0, 1},
    {1, 0, 1},
  };
  cout << "walkable: " << walkable << endl;

  cout << test_reachability(walkable) << endl;

  return 0;
}
