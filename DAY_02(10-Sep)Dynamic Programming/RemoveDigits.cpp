/*
Author : shhiivaam
*/
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
vector<int> dp;
int Solve(int n) {
    if (n == 0) return 0;
    if (dp[n] != -1) return dp[n];
    int ans = INF;
    int temp = n;
    while (temp > 0) {
        int d = temp % 10;
        temp /= 10;
        if (d > 0) ans = min(ans, 1 + Solve(n - d));
    }
    return dp[n] = ans;
}

void solve() {
    int n;
    cin >> n;
    dp.assign(n + 1, -1);
    cout << Solve(n) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

