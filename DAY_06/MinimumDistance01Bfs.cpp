#include<iostream>
#include<queue>
#include<climits>
using namespace std;
int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};
int n, m;
int bfs(int sr, int sc, vector<vector<int>>& gp) {
    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q;
    vis[sr][sc] = 1;
    q.push({{sr, sc}, 0});
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        int x = cur.first.first;
        int y = cur.first.second;
        int d = cur.second;
        if (gp[x][y] == 1) {
            return d;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]) {
                vis[nx][ny] = 1;
                q.push({{nx, ny}, d + 1});
            }
        }
    }
    return INT_MAX;
}
int main() {
    cin >> n >> m;
    vector<vector<int>> gp(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> gp[i][j];
        }
    }
    vector<vector<int>> dis(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (gp[i][j] == 0) {
                dis[i][j] = bfs(i, j, gp);
            } else {
                dis[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dis[i][j] << " ";
        }
        cout << endl;
    }
}
