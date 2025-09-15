#include<iostream>
#include<queue>
using namespace std;
int n,m;
void Dijkstra(pair<int,int>st, vector<vector<int>>&mtx,vector<vector<int>>&dist){
 queue<pair<pair<int,int>,int>>q;
 q.push({st,0});
 dist[st.first][st.second]=0;
 while(!q.empty()){
    auto it = q.front();
    int sr = it.first.first;
    int sc = it.first.second;
    int dis = it.second;
    q.pop();
    int dx[]={1,0,-1,0};
    int dy[]={0,1,0,-1};
    for(int i =0;i<4;i++){
        int nx = sr + dx[i];
        int ny = sc + dy[i];
       if(nx >= 0 && nx < n && ny >=0 && ny<m && mtx[nx][ny] == 1){
           if(dist[sr][sc] + 1 < dist[nx][ny]){
                dist[nx][ny] = dist[sr][sc] + 1;
                q.push({{nx,ny},dist[sr][sc]+1});
          }
       } 
    }
 }
}
int main(){
    cin>>n>>m;
    vector<vector<int>>mtx(n,vector<int>(m));
    for(int i = 0;i<n;i++){
        for(int j =0;j<m;j++){
            cin>>mtx[i][j];
        }
    }
    pair<int,int>st;
    cin>>st.first>>st.second;
    pair<int,int>en;
    cin>>en.first>>en.second;
    vector<vector<int>>dist(n,vector<int>(m,1e9));
    Dijkstra(st,mtx,dist);
    cout<<dist[en.first][en.second]<<endl;
}
