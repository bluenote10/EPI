#include "convenience.hpp"


void traverse(const vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j, int N, int M) {

  visited[i][j] = true;

  const vector<vector<int>> shifts = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  for (const auto& s : shifts) {
    int nx = i + s[0];
    int ny = j + s[1];
    if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny] && grid[nx][ny] == 0) {
      traverse(grid, visited, nx, ny, N, M);
    }
  }
}


void flip_unreachable(vector<vector<int>>& grid) {
  const int N = grid.size();
  const int M = grid[0].size();
  vector<vector<bool>> visited(N, vector<bool>(M, false));

  auto rows = {0, N-1};
  auto cols = {0, M-1};

  for (auto i : rows) {
    for (int j = 0; j < M; ++j) {
      if (grid[i][j] == 0 && !visited[i][j]) {
        cout << "traversing from " << i << " " << j << endl;
        traverse(grid, visited, i, j, N, M);
      }
    }
  }
  for (auto j : cols) {
    for (int i = 0; i < N; ++i) {
      if (grid[i][j] == 0 && !visited[i][j]) {
        cout << "traversing from " << i << " " << j << endl;
        traverse(grid, visited, i, j, N, M);
      }
    }
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (grid[i][j] == 0 && !visited[i][j]) {
        grid[i][j] = 1;
      }
    }
  }

}

int main(int argc, char** args) {

  vector<vector<int>> grid = {
    {1, 0, 1, 0, 1, 1},
    {1, 1, 0, 1, 1, 1},
    {0, 0, 0, 0, 0, 1},
    {0, 1, 0, 1, 1, 1},
    {1, 0, 1, 0, 0, 0},
  };

  flip_unreachable(grid);

  for (auto r : grid) {
    cout << r << endl;
  }

  return 0;
}