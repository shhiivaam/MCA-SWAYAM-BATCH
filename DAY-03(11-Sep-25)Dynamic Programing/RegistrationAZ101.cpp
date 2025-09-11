#include <bits/stdc++.h>
using namespace std;
#define IOS                
  ios::sync_with_stdio(0); 
  cin.tie(0);             
  cout.tie(0);

int main() {
  IOS int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    map<string, int> m;
    for (int i = 0; i < n; ++i) {
      string s;
      cin >> s;
      if (!m.count(s)) {
        cout << "OK\n";
      } else {
        cout << s << m[s] << "\n";
      }
      m[s]++;
    }
  }
  return 0;
}

