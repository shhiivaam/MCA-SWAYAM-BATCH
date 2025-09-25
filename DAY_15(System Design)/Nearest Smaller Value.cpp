#include <bits/stdc++.h>
using namespace std;

#define IOS                \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);

int main() {
  IOS int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    stack<int> s;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      while (!s.empty() && a[s.top()] >= a[i]) {
        s.pop();
      }
      if (s.empty()) {
        cout << "0 ";
      } else {
        cout << s.top() + 1 << " ";
      }
      s.push(i);
    }
    cout << "\n";
  }
  return 0;
}

