#include<iostream>
#include<vector>
using namespace std;
bool possible(int x, int y, int n, int m, vector<vector<char>>& mtx, vector<vector<int>>& vis) {
    return (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && mtx[x][y] == '1');
}
void dfs(int sr, int sc, int n, int m, vector<vector<char>>& mtx, vector<vector<int>>& vis) {
    vis[sr][sc] = 1;
    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, 1, -1, 0};
    for (int i = 0; i < 4; i++) {
        int nx = sr + dx[i];
        int ny = sc + dy[i];
        if (possible(nx, ny, n, m, mtx, vis)) {
            dfs(nx, ny, n, m, mtx, vis);
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> mtx(n, vector<char>(m));
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mtx[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        if (mtx[i][0] == '1') dfs(i, 0, n, m, mtx, vis);
        if (mtx[i][m-1] == '1') dfs(i, m-1, n, m, mtx, vis);
    }
    for (int i = 0; i < m; i++) {
        if (mtx[0][i] == '1') dfs(0, i, n, m, mtx, vis);
        if (mtx[n-1][i] == '1') dfs(n-1, i, n, m, mtx, vis);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && mtx[i][j] == '1') cnt++;
        }
    }
    cout << cnt << endl;
}
