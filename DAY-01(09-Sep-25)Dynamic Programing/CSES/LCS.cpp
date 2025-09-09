/*
Author : shhiivaam
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> a, b;
int dp[3005][3005];

int Rec(int i, int j, int n, int m) {
    if (i == n || j == m) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    int ans = 0;
    ans = max(ans, Rec(i + 1, j, n, m));     
    ans = max(ans, Rec(i, j + 1, n, m));
    if (a[i] == b[j]) {
        ans = max(ans, 1 + Rec(i + 1, j + 1, n, m)); // match found
    }
    return dp[i][j] = ans;
}

void generate(int i, int j, int n, int m) {
    if (i == n || j == m) return;

    if (a[i] == b[j]) {
        cout << a[i] << " ";  // print matched element
        generate(i + 1, j + 1, n, m);
    }
    else {
        if (dp[i + 1][j] > dp[i][j + 1]) {
            generate(i + 1, j, n, m);
        }
        else {
            generate(i, j + 1, n, m);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    a.resize(n);
    b.resize(m);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int j = 0; j < m; j++) cin >> b[j];

    memset(dp, -1, sizeof(dp));
    cout << Rec(0, 0, n, m) << "\n";  

    generate(0, 0, n, m);  
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
