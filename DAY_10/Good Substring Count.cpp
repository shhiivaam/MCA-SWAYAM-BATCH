#include <bits/stdc++.h>
using namespace std;
bool isGood(const vector<int>& freq) {
    int val = 0;
    for (int f : freq) {
        if (f > 0) {
            if (val == 0) val = f;
            else if (f != val) return false;
        }
    }
    return true;
}
void solve() {
    string s;
    cin >> s;
    int ans = 0;

    for (int i = 0; i < (int)s.length(); i++) {
        vector<int> freq(26, 0);
        for (int j = i; j < (int)s.length(); j++) {
            freq[s[j] - 'a']++;
            if (isGood(freq)) ans++;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
