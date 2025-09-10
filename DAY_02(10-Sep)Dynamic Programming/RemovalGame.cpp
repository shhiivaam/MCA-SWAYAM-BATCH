/*
Author : shhiivaam
*/
#include <bits/stdc++.h>
using namespace std;
int Solve(int l, int r, vector<int> &nums, vector<vector<int>> &dp) {
    if (l > r) return 0;
    if (dp[l][r] != -1) return dp[l][r];
    int pickLeft = nums[l] + min(Solve(l+2, r, nums, dp), Solve(l+1, r-1, nums, dp));
    int pickRight = nums[r] + min(Solve(l, r-2, nums, dp), Solve(l+1, r-1, nums, dp));
    return dp[l][r] = max(pickLeft, pickRight);
}
void solve(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << Solve(0, n-1, nums, dp) << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
