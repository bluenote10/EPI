#include "convenience.hpp"

#include <algorithm>

using freqmap = vector<pair<double, char>>;
using codemap = vector<pair<string, char>>;


string convert_to_codestring(int code, int codesize) {
  string result;
  while (codesize > 0) {
    auto add = ((code & 1) == 1 ? '1' : '0');
    result.push_back(add);
    code >>= 1;
    codesize--;
  }
  reverse(result.begin(), result.end());
  return result;
}

codemap prefix_rec(freqmap frequencies, string prefix, double threshold, int codesize) {
  codemap generated_codes;

  cout << frequencies << endl;
  
  int code = 0;
  for (int j=frequencies.size()-1; j>=0; --j) {
    double frq = frequencies[j].first;
    char   chr = frequencies[j].second;
    cout << frq << endl;
    if (frq >= threshold) {
      auto codestring = prefix + convert_to_codestring(code, codesize);
      generated_codes.emplace_back(codestring, chr);
      cout << "added code: " << generated_codes << endl;
      frequencies.pop_back();
      code += 1;
    } else {
      break;
    }
  }

  if (frequencies.size() > 0) {
    if (code > 0) {
      // if we could generate at least one code, generate the remaining frequencies as a prefix
      auto codestring = convert_to_codestring(code, codesize);
      auto new_prefix = prefix + codestring;

      // use "half of the sum of the remaining frequencies" as the new threshold
      double new_threshold = 0;
      for (const auto& f : frequencies) {
        new_threshold += f.first;
      }
      
      auto subcodes = prefix_rec(frequencies, new_prefix, new_threshold/2, 1);
      generated_codes.insert(generated_codes.end(), subcodes.begin(), subcodes.end());
    } else {
      // if no code has been generated, reduce threshold and codesize
      auto subcodes = prefix_rec(frequencies, prefix, threshold/2, codesize+1);
      generated_codes.insert(generated_codes.end(), subcodes.begin(), subcodes.end());
    }
  }
  
  //codemap suffix_codes = prefix_rec(frequencies, )
  return generated_codes;
}



int main(int argc, char** args) {

  //freqmap frequencies{{0.1, 'C'}, {0.1, 'B'}, {0.8, 'A'}};
  //freqmap frequencies{{0.25, 'C'}, {0.25, 'C'}, {0.25, 'B'}, {0.25, 'A'}};

  freqmap frequencies{
    {0.0817, 'A'},
    {0.0149, 'B'},
    {0.0278, 'C'},
    {0.0425, 'D'},
    {0.1270, 'E'},
    {0.0223, 'F'},
    {0.0202, 'G'},
    {0.0609, 'H'},
    {0.0697, 'I'},
    {0.0015, 'J'},
    {0.0077, 'K'},
    {0.0403, 'L'},
    {0.0241, 'M'},
    {0.0675, 'N'},
    {0.0751, 'O'},
    {0.0193, 'P'},
    {0.0010, 'Q'},
    {0.0599, 'R'},
    {0.0633, 'S'},
    {0.0906, 'T'},
    {0.0276, 'U'},
    {0.0098, 'V'},
    {0.0236, 'W'},
    {0.0015, 'X'},
    {0.0197, 'Y'},
    {0.0007, 'Z'},
  };
  sort(frequencies.begin(), frequencies.end());
  cout << frequencies << endl;
 
  
  auto codes = prefix_rec(frequencies, "", 0.5, 1);

  cout << "All codes:\n" << codes << endl;
  
  return 0;
}
