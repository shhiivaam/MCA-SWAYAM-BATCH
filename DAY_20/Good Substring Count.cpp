#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
bool isGoodSubstring(const unordered_map<char, int>& freq) {
  int common_freq = -1;
  for (const auto& entry : freq) {
    if (common_freq == -1) {
      common_freq = entry.second;
    } else if (entry.second != common_freq) {
      return false;
    }
  }
  return true;
}
int countGoodSubstrings(const string& s) {
  int n = s.size();
  int good_count = 0;

  
  for (int i = 0; i < n; ++i) {
    unordered_map<char, int> freq;  

   
    for (int j = i; j < n; ++j) {
      freq[s[j]]++;  
      if (isGoodSubstring(freq)) {
        good_count++;
      }
    }
  }

  return good_count;
}

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;

    cout << countGoodSubstrings(s) << "\n";
  }
  return 0;
}
