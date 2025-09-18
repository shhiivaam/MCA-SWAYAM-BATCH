#include <bits/stdc++.h>
using namespace std;
 
vector<vector<int>> gp;
vector<int> parent, vis;
int startNode = -1, endNode = -1;
 
bool dfs(int node, int par) {
    vis[node] = 1;
    for (auto v : gp[node]) {
        if (v == par) continue;  
        if (!vis[v]) {
            parent[v] = node;
            if (dfs(v, node)) return true;
        } else {
            
            startNode = v;
            endNode = node;
            return true;
        }
    }
    return false;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, m;
    cin >> n >> m;
    gp.assign(n + 1, {});
    parent.assign(n + 1, -1);
    vis.assign(n + 1, 0);
 
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        gp[a].push_back(b);
        gp[b].push_back(a);
    }
 
    bool found = false;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (dfs(i, -1)) {
                found = true;
                break;
            }
        }
    }
 
    if (!found) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int> cycle;
        cycle.push_back(startNode);
        for (int v = endNode; v != startNode; v = parent[v]) {
            cycle.push_back(v);
        }
        cycle.push_back(startNode);
        reverse(cycle.begin(), cycle.end());
 
        cout << cycle.size() << "\n";
        for (auto x : cycle) cout << x << " ";
        cout << "\n";
    }
}
