/*
Author : shhiivaam
*/
#include <bits/stdc++.h>
using namespace std;
int editDistance(int i, int j, string &w, string &s, vector<vector<int>> &dp) {
    if (i < 0) return j + 1; 
    if (j < 0) return i + 1; 
    if (dp[i][j] != -1) return dp[i][j];
    if (w[i] == s[j]) 
        return dp[i][j] = editDistance(i - 1, j - 1, w, s, dp);
    int delOp = 1 + editDistance(i - 1, j, w, s, dp);
    int insOp = 1 + editDistance(i, j - 1, w, s, dp);
    int repOp = 1 + editDistance(i - 1, j - 1, w, s, dp);
    return dp[i][j] = min({delOp, insOp, repOp});
}
void solve() {
    string word1, word2;
    cin >> word1 >> word2;
    int n = word1.length();
    int m = word2.length();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int ans = editDistance(n - 1, m - 1, word1, word2, dp);
    cout << ans << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
