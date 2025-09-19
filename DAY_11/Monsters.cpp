#include <bits/stdc++.h>
using namespace std;
struct Node {
    int x, y;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    vector<vector<int>> monsterTime(n, vector<int>(m, 1e9));
    vector<vector<int>> dist(n, vector<int>(m, -1));
    vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m, {-1,-1}));

    queue<Node> q;

    int startX, startY;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'M') {
                monsterTime[i][j] = 0;
                q.push({i,j});
            }
            if (grid[i][j] == 'A') {
                startX = i;
                startY = j;
            }
        }
    }

    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    char moveChar[4] = {'D','U','R','L'};
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = cur.x + dx[k];
            int ny = cur.y + dy[k];
            if (nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny] != '#') {
                if (monsterTime[nx][ny] > monsterTime[cur.x][cur.y] + 1) {
                    monsterTime[nx][ny] = monsterTime[cur.x][cur.y] + 1;
                    q.push({nx,ny});
                }
            }
        }
    }
    queue<Node> q2;
    dist[startX][startY] = 0;
    q2.push({startX, startY});

    while (!q2.empty()) {
        auto cur = q2.front(); q2.pop();
        if (cur.x == 0 || cur.x == n-1 || cur.y == 0 || cur.y == m-1) {
            cout << "YES\n";
            cout << dist[cur.x][cur.y] << "\n";
            string path = "";
            int x = cur.x, y = cur.y;
            while (!(x == startX && y == startY)) {
                auto p = parent[x][y];
                for (int k = 0; k < 4; k++) {
                    if (x == p.first + dx[k] && y == p.second + dy[k]) {
                        path.push_back(moveChar[k]);
                    }
                }
                x = p.first;
                y = p.second;
            }
            reverse(path.begin(), path.end());
            cout << path << "\n";
            return 0;
        }

        for (int k = 0; k < 4; k++) {
            int nx = cur.x + dx[k];
            int ny = cur.y + dy[k];
            if (nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny] != '#') {
                if (dist[nx][ny] == -1 && dist[cur.x][cur.y] + 1 < monsterTime[nx][ny]) {
                    dist[nx][ny] = dist[cur.x][cur.y] + 1;
                    parent[nx][ny] = {cur.x, cur.y};
                    q2.push({nx,ny});
                }
            }
        }
    }

    cout << "NO\n";
}
