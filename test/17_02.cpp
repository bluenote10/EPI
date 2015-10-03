#include "convenience.hpp"


//int fill_distances(string s1, string s2, vector<vector)

int min(int a, int b, int c) {
  return min(min(a, b), c);
}

int edit_dist(string a, string b) {
  vector<vector<int>> distances(a.size(), vector<int>(b.size()));

  for (size_t i=0; i<a.size(); ++i) {
    for (size_t j=0; j<b.size(); ++j) {
      if (i == 0 && j == 0) {
        distances[i][j] = (a[i] == b[j] ? 0 : 1);
      } else {
        int pi = i-1;
        int pj = j-1;
        int dist_pj = (pj != -1 ? distances[i][pj] : 1);
        int dist_pi = (pi != -1 ? distances[pi][j] : 1);
        int dist_pipj = (pi != -1 && pj != -1 ? distances[pi][pj] : (pi+pj == -2 ? 0 : i+j));

        dist_pi += 1; // (a[i] == b[j] ? 0 : 1);
        dist_pj += 1; // (a[i] == b[j] ? 0 : 1);
        dist_pipj += (a[i] == b[j] ? 0 : 1);

        if (pi != -1 && pj != -1) {
          distances[i][j] = min(dist_pi, dist_pj, dist_pipj);
        } else if (pi == -1) {
          distances[i][j] = dist_pj;
        } else {
          distances[i][j] = dist_pi;
        }

        cout << dist_pi << " " << dist_pj << " " << dist_pipj << " " << a[i] << " " << b[j] << endl;
        cout << i << " " << j << " " << distances << endl;
      }
    }
  }

  return distances[a.size()-1][b.size()-1];
}


int main(int argc, char** args) {

  auto tests = {make_pair("Orchestra", "Carthorse")};

  for (auto t : tests) {
    cout << edit_dist(t.first, t.second) << endl;
  }
  
  return 0;
}


