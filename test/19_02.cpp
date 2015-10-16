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



struct Coordinate {
  bool operator==(const Coordinate& that) const {
    return x == that.x && y == that.y;
  }

  int x, y;
};

bool SearchHelper(vector<vector<int>>& maze, const Coordinate& cur, const Coordinate& e, vector<Coordinate>& path) {

  if (cur == e) {
    return true;
  }

  const int w = maze.size();
  const int h = maze[0].size();

  vector<vector<int>> shifts = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  for (const auto& shift : shifts) {
    int nx = cur.x + shift[0];
    int ny = cur.y + shift[1];
    if (nx >= 0 && nx < w && ny >= 0 && ny < h && maze[nx][ny] == 0) {
      path.push_back(Coordinate{nx, ny});
      maze[nx][ny] = 1;
      bool isgood = SearchHelper(maze, path.back(), e, path);
      if (isgood) {
        return true;
      } else {
        path.pop_back();
      }
    }
  }
  return false;
}

vector<Coordinate> SearchMaze(vector<vector<int>> maze, const Coordinate& s, const Coordinate& e) {

  vector<Coordinate> path;

  // mark start as processed and add to path
  maze[s.x][s.y] = 1;
  path.push_back(s);

  if (!SearchHelper(maze, s, e, path)) {
    // if there is no path make it fully empty
    path.pop_back();
  }

  return path;
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
