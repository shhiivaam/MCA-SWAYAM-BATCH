#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<string> grid;
vector<vector<bool>> visited;
vector<vector<pair<int, int>>> parent;
 
int dx[] = {-1, 0, 1, 0};  
int dy[] = {0, -1, 0, 1};
char dir[] = {'U', 'L', 'D', 'R'};
 
bool is_valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#' && !visited[x][y];
}
 
bool bfs(pair<int, int> start, pair<int, int> end) {
    visited.assign(n, vector<bool>(m, false));
    parent.assign(n, vector<pair<int, int>>(m, {-1, -1}));
 
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;
 
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
 
        if (make_pair(x, y) == end) return true;
 
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (is_valid(nx, ny)) {
                visited[nx][ny] = true;
                parent[nx][ny] = {x, y};
                q.push({nx, ny});
            }
        }
    }
    return false;
}
 
string reconstruct_path(pair<int, int> start, pair<int, int> end) {
    string path;
    pair<int, int> cur = end;
 
    while (cur != start) {
        auto [px, py] = parent[cur.first][cur.second];
        for (int i = 0; i < 4; ++i) {
            if (px + dx[i] == cur.first && py + dy[i] == cur.second) {
                path.push_back(dir[i]);
                break;
            }
        }
        cur = {px, py};
    }
    reverse(path.begin(), path.end());
    return path;
}
 
int main() {
    cin >> n >> m;
    grid.resize(n);
    pair<int, int> start, end;
 
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'A') start = {i, j};
            if (grid[i][j] == 'B') end = {i, j};
        }
    }
 
    if (bfs(start, end)) {
        string path = reconstruct_path(start, end);
        cout << "YES\n";
        cout << path.length() << "\n";
        cout << path << "\n";
    } else {
        cout << "NO\n";
    }
 
    return 0;
}
