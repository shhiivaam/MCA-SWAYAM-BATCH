/*
Author : shhiivaam
*/
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int n, T;
vector<vector<int>> dp;
int solve(int i, int s) {
    if (s == 0) return 1;
    if (i > n || s < 0) return 0;
    int &res = dp[i][s];
    if (res != -1) return res;
    long long take = solve(i + 1, s - i);
    long long skip = solve(i + 1, s);
    return res = (take + skip) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    long long S = 1LL * n * (n + 1) / 2;
    if (S % 2) {
        cout << 0 << "\n";
        return 0;
    }

    T = (int)(S / 2);
    dp.assign(n + 2, vector<int>(T + 1, -1));
    long long ans = solve(1, T);
    long long inv2 = (MOD + 1) / 2;
    cout << (ans * inv2) % MOD << "\n";
    return 0;
}
