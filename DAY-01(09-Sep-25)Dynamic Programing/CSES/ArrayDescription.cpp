/*
Author : shhiivaam
*/
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<vector<int>> dp(n, vector<int>(m + 1, 0));
    if (v[0] == 0) {
        for (int x = 1; x <= m; x++) dp[0][x] = 1;
    } else {
        dp[0][v[0]] = 1;
    }
    for (int i = 1; i < n; i++) {
        if (v[i] == 0) {
            for (int x = 1; x <= m; x++) {
                long long ways = 0;
                for (int d = -1; d <= 1; d++) {
                    int prev = x + d;
                    if (prev >= 1 && prev <= m) {
                        ways += dp[i - 1][prev];
                    }
                }
                dp[i][x] = ways % MOD;
            }
        } else {
            int x = v[i];
            long long ways = 0;
            for (int d = -1; d <= 1; d++) {
                int prev = x + d;
                if (prev >= 1 && prev <= m) {
                    ways += dp[i - 1][prev];
                }
            }
            dp[i][x] = ways % MOD;
        }
    }
    long long ans = 0;
    for (int x = 1; x <= m; x++) {
        ans = (ans + dp[n - 1][x]) % MOD;
    }
    cout << ans << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

