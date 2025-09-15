#include<iostream>
#include<vector>
#include<string>
#include<deque>
#include<algorithm>
using namespace std;
int n, m;
const int INF = 1e9;
using state = pair<int, int>;
vector<string> arr;
vector<vector<int>> vis, dis;

bool can_place(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

vector<pair<state, int>> neighbour(state st) {
    vector<pair<state, int>> ans;
    for (int i = 0; i < 4; i++) {
        int nx = st.first + dx[i];
        int ny = st.second + dy[i];
        if (can_place(nx, ny)) {
            if (arr[nx][ny] == '#') {
                ans.push_back({{nx, ny}, 1});
            } else {
                ans.push_back({{nx, ny}, 0});
            }
        }
    }
    return ans;
}

void bfs(state st) {
    vis = vector<vector<int>>(n, vector<int>(m, 0));
    dis = vector<vector<int>>(n, vector<int>(m, INF));
    deque<state> dq;
    dis[st.first][st.second] = 0;
    dq.push_front(st);
    while (!dq.empty()) {
        state cur = dq.front();
        dq.pop_front();
        if (vis[cur.first][cur.second]) continue;
        vis[cur.first][cur.second] = 1;
        for (auto [v, c] : neighbour(cur)) {
            int new_dist = dis[cur.first][cur.second] + c;
            if (dis[v.first][v.second] > new_dist) {
                dis[v.first][v.second] = new_dist;
                if (c == 0)
                    dq.push_front(v);
                else
                    dq.push_back(v);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    arr.resize(n);
    state st, en;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 'S') {
                st = {i, j};
            } else if (arr[i][j] == 'E') {
                en = {i, j};
            }
        }
    }
    bfs(st);
    if (vis[en.first][en.second]) {
        cout << dis[en.first][en.second] << " ";
    } else {
        cout << "-1\n";
    }
}
/* 5 8
S####
....#
####.
####.
#E...*/
