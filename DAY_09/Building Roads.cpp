#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<vector<int>>& gp, vector<int>& vis) {
    vis[node] = 1;
    for (auto v : gp[node]) {
        if (!vis[v]) dfs(v, gp, vis);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, m;
    cin >> n >> m;
 
    vector<vector<int>> gp(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        gp[a].push_back(b);
        gp[b].push_back(a);
    }
 
    vector<int> vis(n + 1, 0);
    vector<int> reps; 
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, gp, vis);
            reps.push_back(i);
        }
    }
    int needed = (int)reps.size() - 1;
    cout << needed << "\n";
    for (int i = 0; i < (int)reps.size() - 1; i++) {
        cout << reps[i] << " " << reps[i + 1] << "\n";
    }
 
    return 0;
}
