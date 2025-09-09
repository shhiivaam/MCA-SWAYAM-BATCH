/*
Author : shhiivaam
*/
#include <bits/stdc++.h>
using namespace std;
void Solve(int idx, vector<int>& coins, int sum, set<int>& st) {
    if (idx == (int)coins.size()) {
        if (sum > 0) st.insert(sum);
        return;
    }
    Solve(idx + 1, coins, sum, st);
    Solve(idx + 1, coins, sum + coins[idx], st);
}
void solve() {
    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];
    set<int> st;
    Solve(0, coins, 0, st);
    cout << st.size() << "\n";
    for (int v : st) cout << v << " ";
    cout << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
