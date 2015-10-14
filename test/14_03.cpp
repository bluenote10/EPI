#include "convenience.hpp"

#include <algorithm>

void remove_duplicates(vector<string>& data) {
  if (data.size() <= 1) return;
  sort(data.begin(), data.end());
  int i = 0;
  bool skip = false;
  for (size_t j=1; j<data.size(); ++j) {
    // when we see a change ...
    if (data[j] != data[j-1]) {
      // .. we only store if this has not been marked as a duplicate
      if (!skip) {
        data[i++] = data[j-1];
      }
      skip = false;
    } else {
      // .. which we do once we see a "current == previous".
      skip = true;
    }
  }
  data.resize(i);
}

int main(int argc, char** args) {

  vector<string> names = {"John", "Jimmy", "Tom", "Anne", "Jimmy", "Tom", "Anne", "John"};

  remove_duplicates(names);

  cout << names << endl;

  return 0;
}


