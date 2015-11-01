#include "convenience.hpp"

vector<pair<string, string>> FindChain(const vector<pair<string, string>>& tickets) {

  unordered_map<string, int> airport_count;
  unordered_map<string, int> start_at;

  for (int i = 0; i < tickets.size(); ++i) {
    const string& from = tickets[i].first;
    const string& to = tickets[i].second;

    --airport_count[from];
    ++airport_count[to];

    start_at[from] = i;
  }
  cout << airport_count << endl;
  cout << start_at << endl;

  string first_airport;
  for (const auto& c : airport_count) {
    if (c.second == -1) {
      first_airport = c.first;
    }
  }

  vector<pair<string, string>> chain;
  chain.push_back(tickets[start_at[first_airport]]);
  while (chain.size() < tickets.size()) {
    /*
    const string last = chain.back().second;
    auto next_idx = start_at[last];
    chain.push_back(tickets[next_idx]);
    start_at.erase(last);
    cout << "after deleting " << last << endl;
    cout << start_at << endl;
    */
    const string& last = chain.back().second;
    auto it = start_at.find(last);
    chain.push_back(tickets[it->second]);
    start_at.erase(it);
    cout << "after deleting " << *it << endl;
    cout << start_at << endl;
  }

  return chain;
}


int main(int argc, char** args) {
  vector<pair<string, string>> tickets = {{"FRA", "BER"}, {"NY", "FRA"}, {"SFO", "NY"}, {"BER", "XXX"}};

  auto result = FindChain(tickets);

  cout << result << endl;
}
