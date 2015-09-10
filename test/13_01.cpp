
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

#include "convenience.hpp"

using namespace std;


void gen_anagram(const vector<string> &words) {
  unordered_map<string, vector<string>> groups;
  for (const auto& word : words) {
    string word_sorted = word;
    sort(word_sorted.begin(), word_sorted.end());
    groups[word_sorted].push_back(word);
    cout << word << endl;
  }

  // well, and now filter groups with count == 1, but boring
  for (const auto& x : groups) cout << x << endl;
}


int main(int argc, char** args) {

  vector<string> words{"debitcard", "elvis", "silent", "badcredit", "lives", "freedom", "listen", "levis"};
  
  gen_anagram(words);
  
  return 0;
}
