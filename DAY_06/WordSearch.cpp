#include<iostream>
using namespace std;
int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};
int n,m;
bool can_mov(int x,int y,vector<vector<char>>&gp,vector<vector<int>>&vis,char ch){
    return (x>=0 && x<n && y>=0 && y<m && !vis[x][y] && gp[x][y] == ch);
}
bool dfs(int lev,int sr, int sc,vector<vector<char>>&gp,vector<vector<int>>&vis,string&s){
     if(lev == s.length()-1){
          return true;
     }
    vis[sr][sc]=1;
    char ch =s[lev+1];
    for(int i=0;i<4;i++){
        int nx = sr + dx[i];
        int ny = sc + dy[i];
    if(can_mov(nx,ny,gp,vis,ch)){  
       if(dfs(lev+1,nx,ny,gp,vis,s)){
           return true;
        }
      }
    }
  vis[sr][sc]=0;
 return false;    
}
int main(){
    int t; cin>>t;
    while(t--){
     cin>>n>>m;
    vector<vector<char>>gp(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>gp[i][j];
        }
    }
    vector<vector<int>>vis(n,vector<int>(m,0));
    string word; cin>>word;
     bool pre=false;
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(gp[i][j] == word[0]){
                if(dfs(0,i,j,gp,vis,word)==true){
                  pre =true;
                  break;
                }
            }
        }
    }
   if(pre){
       cout<<"True"<<endl;
   }else{
       cout<<"False"<<endl;
   }  
  }  
}
