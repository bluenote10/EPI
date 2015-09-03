
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

vector<int> merge_vectors_naive(const vector<vector<int>>& vectors) {

  // determine the total size of the output vector
  int total_len = 0;
  for (const auto &v : vectors) {
    total_len += v.size();
  }
  cout << total_len << endl;

  // prepare output vector
  vector<int> res;
  res.reserve(total_len);
  
  // prepare indices
  vector<int> indices(vectors.size());

  int processed = 0;
  while (processed < total_len) {
    int best_ind = -1;
    int best_val = numeric_limits<int>::max();
    for (int i=0; i<vectors.size(); ++i) {
      int index = indices[i];
      if (index < vectors[i].size()) {
        int value = vectors[i][index];
        if (value < best_val) {
          best_ind = i;
          best_val = value;
        }
      }
    }
    cout << "best_ind = " << best_ind << " best_val = " << best_val << endl;
    res.push_back(best_val);
    indices[best_ind]++;
    processed++;
  }
  
  return res;
}


template <typename V, typename T, typename Mapper>
vector<V> map(const vector<T> &in, Mapper f) {
  vector<V> out;
  out.reserve(in.size());
  for (const auto &x : in) {
    V res = f(x);
    out.push_back(res);
  }
  return out;
}

vector<int> merge_vectors(const vector<vector<int>>& vectors) {
  vector<vector<int>::const_iterator> iterators =
    map<vector<int>::const_iterator>(vectors, [](const vector<int> &v){ return v.cbegin(); }); // why does pass by value fail?

  auto comp = [](pair<int,int> a, pair<int,int> b){ return a.first > b.first; };
  
  // init heap
  vector<pair<int,int>> heap;
  heap.reserve(vectors.size());
  for (int i=0; i<vectors.size(); ++i) {
    if (iterators[i] != vectors[i].cend()) {
      heap.push_back({*iterators[i], i});
    }
  }
  make_heap(heap.begin(), heap.end(), comp);

  // prepare output
  vector<int> res;

  while (heap.size() > 0) {
    pop_heap(heap.begin(), heap.end(), comp);
    auto next_min = heap.back();
    heap.pop_back();

    int val = next_min.first;
    int ind = next_min.second;

    res.push_back(val);
    cout << val << " " << ind << endl;

    iterators[ind]++;
    if (iterators[ind] != vectors[ind].cend()) {
      heap.push_back({*iterators[ind], ind});
      push_heap(heap.begin(), heap.end(), comp);
    }
  }
  return res;
}



int main(int argc, char** argv) {

  vector<vector<int>> vecs = {
    {1,2,3},
    {2,2},
    {0,5},
    {1,1,2},
  };

  auto result = merge_vectors(vecs);
  for (auto x : result)
    cout << x << endl;
  
  return 0;
}
