#include "convenience.hpp"

#include <numeric>
#include <unordered_set>

template <typename T>
using uset = unordered_set<T>;


struct Queen {
  int i, j;
};

bool operator==(const Queen& lhs, const Queen& rhs)
{
  return lhs.i == rhs.i && lhs.j == lhs.j;
}

namespace std
{
template <> struct hash<Queen>
{
  inline size_t operator()(const Queen& q) const
  {
    size_t seed = 0;
    seed += hash<int>()(q.i);
    seed <<= hash<int>()(q.j);
    return seed;
  }
};
}



struct Board {

public:

  Board(int size) : size(size) {}
  
  bool is_allowed_at(int i, int j) const {
    for (const Queen& q : queens) {
      if (q.i == i) return false;
      if (q.j == j) return false;
      int di = q.i - i;
      int dj = q.j - j;
      //cout << di << " " << dj << endl;
      if (abs(di) == abs(dj)) return false;
    }
    return true;
  }

  void add(int i, int j) {
    queens.emplace(Queen{i,j});
  }

  void print() const {
    for (int i=0; i<size; ++i) {
      for (int j=0; j<size; ++j) {
        bool has_queen = false;
        for (const Queen& q : queens) {
          if (q.i == i && q.j == j) has_queen = true;
        }
        if (has_queen)
          cout << "@ ";
        else
          cout << ". ";
      }
      cout << endl;
    }
  }


//private:
public:
  int size;
  uset<Queen> queens;
  
};


bool operator==(const Board& lhs, const Board& rhs) {
  return lhs.queens == rhs.queens;
}


namespace std
{
template <> struct hash<Board>
{
  inline size_t operator()(const Board& b) const
  {
    size_t seed = 0;
    for (const auto& q : b.queens) {
      seed += hash<int>()(q.i);
      seed <<= hash<int>()(q.j);
    }
    return seed;
  }
};
}



void place_queens(uset<int> allowed_i, uset<int> allowed_j, Board b, int to_place, uset<Board>& all_results) {
  if (to_place <= 0)
    return;
  for (auto i : allowed_i) {
    for (auto j : allowed_j) {
      //cout << i << " " << j << endl;
      if (!b.is_allowed_at(i,j))
        continue;
      auto new_allowed_i = allowed_i;
      auto new_allowed_j = allowed_j;
      new_allowed_i.erase(i);
      new_allowed_j.erase(j);
      auto new_board = b;
      new_board.add(i,j);
      place_queens(new_allowed_i, new_allowed_j, new_board, to_place-1, all_results);
      if (to_place == 1) {
        all_results.insert(new_board);
      }
      //new_board.print();
    }
  }
}

void get_n_queens(int n) {
  Board b(n);
  uset<int> allowed_i(n);
  uset<int> allowed_j(n);
  for (int i=0; i<n; ++i) {
    allowed_i.insert(i);
    allowed_j.insert(i);
  }
  //iota(allowed_i.begin(), allowed_i.end(), 0);
  //iota(allowed_j.begin(), allowed_j.end(), 0);

  uset<Board> results;
  place_queens(allowed_i, allowed_j, b, n, results);

  int i = 0;
  for (const auto& r : results) {
    cout << "Result: " << (i+1) << endl;
    r.print();
    i++;
  }
  /*
  for (int i=0; i<results.size(); ++i) {
    cout << "Result " << i << endl;
    results[i].print();
  }
  */
  
}


int main(int argc, char** args) {

  get_n_queens(7);
  
  return 0;
}

