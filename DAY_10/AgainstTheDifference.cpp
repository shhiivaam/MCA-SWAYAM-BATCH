#include<bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> pos(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    vector<long long> dp(n + 1, 0);
    vector<int> occurrence_count(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        dp[i + 1] = dp[i];
        int val = a[i];
        occurrence_count[val]++;
        int k = occurrence_count[val];
        if (k >= val) {
            int start_block_index = pos[val][k - val];
            long long prev_length = dp[start_block_index];
            long long new_length = prev_length + val;
            dp[i + 1] = max(dp[i + 1], new_length);
        }
    }
    cout << dp[n] << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
