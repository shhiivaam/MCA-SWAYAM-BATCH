#include <bits/stdc++.h>
using namespace std;
bool Can_move(int i, int j, int n, int m,vector<vector<char>>&mtx,vector<vector<int>>&vis){
    return(i >= 0 && i < n && j >= 0 && j < m && !vis[i][j] && mtx[i][j] == '.');
}
 
void dfs(int i , int j, int n, int m, vector<vector<char>>&mtx,vector<vector<int>>&vis){
    vis[i][j] = 1;
    
    int dx[]= {1,0,-1,0};
    int dy[]= {0,1,0,-1};
 
    for(int k = 0; k < 4; k++){
        int nx = i + dx[k];
        int ny = j + dy[k];
 
        if(Can_move(nx,ny,n,m,mtx,vis)){
            dfs(nx,ny,n,m,mtx,vis);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
     int n,m; cin>>n>>m;
     vector<vector<char>>mtx(n,vector<char>(m));
     for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>mtx[i][j];
        }
     }
     int NoOfRooms=0;
     vector<vector<int>>vis(n,vector<int>(m,0));
     for(int i = 0;i < n; i++){
        for(int j = 0; j < m; j++){
            if(!vis[i][j] && mtx[i][j] == '.'){
                dfs(i,j,n,m,mtx,vis);
                NoOfRooms++;
            }
        }
     }
    cout<<NoOfRooms<<"\n"; 
    return 0;
}