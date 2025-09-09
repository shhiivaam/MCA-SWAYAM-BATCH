/*
Author : shhiivaam
*/
#include <bits/stdc++.h>
using namespace std;
int n;
vector<string> grid;
vector<vector<string>> dp;
string solve(int i, int j) {
    if (i >= n || j >= n) return string(1, '~');
    if (dp[i][j] != "#") return dp[i][j];
    if (i == n-1 && j == n-1) {
        return dp[i][j] = string(1, grid[i][j]);
    }
    string down = solve(i+1, j);
    string right = solve(i, j+1);
    string best = min(down, right);
    return dp[i][j] = grid[i][j] + best;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    grid.resize(n);
    for (int i = 0; i < n; i++) cin >> grid[i];
    dp.assign(n, vector<string>(n, "#"));
    string ans = solve(0, 0);
    cout << ans << "\n";
    return 0;
}

