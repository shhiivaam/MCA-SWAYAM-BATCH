#include <iostream>
#include <vector>
using namespace std;
bool dfs(int node, vector<vector<int>>& gp, vector<int>& vis, vector<int>& path, vector<int>& check) {
    vis[node] = 1;
    path[node] = 1;
   check[node]=0;
    for (auto v : gp[node]) {
        if (!vis[v]) {
            if (dfs(v, gp, vis, path, check))
                return true;  
        } else if (path[v]) {
            return true;
        }
    }
   check[node] = 1;
    path[node] = 0;
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> gp(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        gp[a].push_back(b);
    }

    vector<int> vis(n, 0);
    vector<int> path(n, 0);
    vector<int> check(n, 0);
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i, gp, vis, path, check);
        }
    }
    for (int i = 0; i < n; i++) {
        if (check[i] == 1) {
            ans.push_back(i);
        }
    }
    for (auto v : ans) cout << v << " ";
    cout << endl;
}
