#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;

void solve() {
    int N, M;
    cin >> N >> M;

    vector<vector<pair<int,int>>> adj(N+1);
    for(int i = 0; i < M; i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<ll> entry(N+1);
    for(int i = 1; i <= N; i++) cin >> entry[i];

    vector<ll> dist(N+1, LLONG_MAX);
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    for(int i = 1; i <= N; i++){
        dist[i] = entry[i];
        pq.push({dist[i], i});
    }
    while(!pq.empty()){
        auto [d,u] = pq.top(); pq.pop();
        if(d != dist[u]) continue;
        for(auto &[v,w] : adj[u]){
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    for(int i = 1; i <= N; i++){
        cout << dist[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}
