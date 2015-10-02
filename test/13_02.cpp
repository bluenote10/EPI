#include "convenience.hpp"

#include <unordered_map>

bool test_possible_palindrome(string s) {
  unordered_map<char, int> counts;
  for (const auto& c : s) {
    counts[c] += 1;
  }
  cout << counts << endl;

  bool uneven_detected = false;
  for (const auto& el : counts) {
    if (el.second % 2 != 0) {
      if (!uneven_detected) {
        uneven_detected = true;
      } else {
        return false;
      }
    }
  }
  return true;
}


int main(int argc, char** args) {

  cout << test_possible_palindrome("abcbc") << endl;
  
  return 0;
}


