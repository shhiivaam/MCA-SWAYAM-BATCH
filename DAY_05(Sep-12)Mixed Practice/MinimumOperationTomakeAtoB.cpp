#include <bits/stdc++.h>
using namespace std;

int Solve(int a, int b, unordered_map<int, int>& dp) {
    if (b <= a) return a - b;
    if (dp.count(b)) return dp[b];

    if (b % 2 == 0) {
        return dp[b] = 1 + Solve(a, b / 2, dp);
    } else {
        return dp[b] = 1 + Solve(a, b + 1, dp);
    }
}

int main() {
    int a, b;
    cin >> a >> b;
    unordered_map<int, int> dp;
    cout << Solve(a, b, dp) << "\n";
    return 0;
}
