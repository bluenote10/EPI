#include "convenience.hpp"

/*
Links regarding BFS vs DFS and stack vs queue:
http://www.ics.uci.edu//~eppstein/161/960215.html
http://cs.stackexchange.com/questions/329/do-you-get-dfs-if-you-change-the-queue-to-a-stack-in-a-bfs-implementation
*/
void paint_boolean(vector<vector<int>>& grid, int i, int j) {
  const int N = grid.size();
  const int M = grid[0].size();

  int color_original = grid[i][j];
  int color_final = !color_original;

  vector<pair<int,int>> stack;
  stack.push_back(make_pair(i, j));

  grid[i][j] = color_final;

  while (stack.size() > 0) {
    auto cur = stack.back();
    stack.pop_back();

    int x = cur.first;
    int y = cur.second;
    cout << x << " " << y << " color " << grid[x][y] << endl;

    vector<vector<int>> shifts = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for (auto const& shift : shifts) {
      int nx = x + shift[0];
      int ny = y + shift[1];
      if (nx >= 0 && nx < N && ny >= 0 && ny < M && grid[nx][ny] == color_original) {
        grid[nx][ny] = color_final;
        stack.push_back(make_pair(nx, ny));
      }
    }
  }
}


int main(int argc, char** args) {

  vector<vector<int>> grid = {
    {1, 0, 1, 0, 1, 1},
    {1, 1, 0, 1, 1, 1},
    {1, 0, 0, 0, 0, 1},
    {0, 1, 0, 1, 1, 1},
    {1, 0, 1, 0, 0, 0},
  };
  vector<vector<int>> grid2 = {
    {1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 1},
    {1, 0, 0, 0, 1, 1},
    {1, 0, 0, 0, 1, 1},
    {1, 1, 1, 1, 1, 1},
  };
  grid = grid2;

  paint_boolean(grid, 2, 2);
  for (auto r : grid) {
    cout << r << endl;
  }

  return 0;
}
