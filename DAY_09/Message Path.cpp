#include <bits/stdc++.h>
using namespace std;

void bfs(int start, vector<int>& vis, vector<vector<int>>& gp, vector<int>& dist, vector<int>& parent) {
    queue<int> q;
    vis[start] = 1;
    dist[start] = 0; 
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto v : gp[node]) {
            if (!vis[v]) {
                vis[v] = 1;
                dist[v] = dist[node] + 1;
                parent[v] = node;   
                q.push(v);
            }
        }
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

    vector<int> vis(n + 1, 0), dist(n + 1, 1e9), parent(n + 1, -1);

    bfs(1, vis, gp, dist, parent);

    if (dist[n] >= 1e9) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << dist[n] + 1 << "\n"; 
        vector<int> path;
        for (int v = n; v != -1; v = parent[v])
            path.push_back(v);
        reverse(path.begin(), path.end());
        for (int v : path) cout << v << " ";
        cout << "\n";
    }
}
