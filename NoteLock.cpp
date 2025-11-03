#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int protected_count = 0;
    int last_surviving_one = -1; 
 
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            int start_window = max(0, i - k + 1);
            if (last_surviving_one < start_window) {
                protected_count++;
            }
            last_surviving_one = i;
        }
    }
 
    cout << protected_count << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
