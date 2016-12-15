#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
  vector<vector<string>> anagrams (vector<string> &strs) {
    unordered_map<string, multiset<string>> ms; 
    for (string s: strs) {
      string t = s;
      sort(t.begin(), t.end());
      ms[t].insert(s);
    }
    vector<vector<string>> ret;
    for (auto m: ms) {
      vector<string> r(m.second.begin(), m.second.end());
      ret.push_back(r);
    }
    return ret;
  }
};

int main() {
}
