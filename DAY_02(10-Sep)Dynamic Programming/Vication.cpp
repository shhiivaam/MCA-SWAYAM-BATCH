/*
Author : shhivaam
*/
#include <bits/stdc++.h>
using namespace std;

int solve(int day, int prev, int n, vector<vector<int>>& mtx, vector<vector<int>>& dp) {
    if (day == n) return 0;
    if (dp[day][prev] != -1) return dp[day][prev];
    int ans = 0;
    for (int activity = 0; activity < 3; activity++) {
        if (activity != prev) { 
            ans = max(ans, mtx[day][activity] + solve(day + 1, activity, n, mtx, dp));
        }
    }
    return dp[day][prev] = ans;
}

void Solve() {
    int n;
    cin >> n;
    vector<vector<int>> mtx(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) cin >> mtx[i][j];
    }
    vector<vector<int>> dp(n, vector<int>(4, -1)); 
    cout << solve(0, 3, n, mtx, dp) << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        Solve();
    }
}
