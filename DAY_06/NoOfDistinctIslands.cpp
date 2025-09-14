#include<iostream>
#include<queue>
#include<set>
using namespace std;
bool check(int x,int y,vector<vector<int>>&mtx, vector<vector<int>>&vis,int n , int m){
    return (x>=0 && x<n && y>=0 && y<m && !vis[x][y] && mtx[x][y]==1);
}
void dfs(int sr,int sc,vector<vector<int>>&mtx, vector<vector<int>>&vis,int n , int m,vector<pair<int,int>>&cur,int i, int j){
    cur.push_back({i-sr,j-sc});
    vis[sr][sc]=1;
    int dx[]={-1,0,0,1};
    int dy[]={0,-1,1,0};
    for(int i=0;i<4;i++){
        int nr = sr + dx[i];
        int nc = sc + dy[i];
        if(check(nr,nc,mtx,vis,n,m)){
            dfs(nr,nc,mtx,vis,n,m,cur,i,j);
        }
    }
}
int main(){
    int n,m; cin>>n>>m;
    vector<vector<int>>mtx(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j =0; j<m; j++){
            cin>>mtx[i][j];
        }
    }
    vector<vector<int>>vis(n,vector<int>(m,0));
    set<vector<pair<int,int>>>st;
    for(int i=0;i<n;i++){
        for(int j = 0; j<m; j++){
            vector<pair<int,int>>cur;
           if(!vis[i][j] && mtx[i][j]==1){
              dfs(i,j,mtx,vis,n,m,cur,i,j);
              st.insert(cur);
           }
        }
    }
   cout<<st.size()<<endl; 
}
