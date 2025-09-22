#include<iostream>
#include<stack>
using namespace std;
void dfs(int node,vector<int>&vis, vector<vector<int>>gp,stack<int>&stk){
    vis[node]=1;
    for(auto v : gp[node]){
        if(!vis[v]){
            dfs(v,vis,gp,stk);
        }
    }
    stk.push(node);
}
int main(){
    int n,m; cin>>n>>m;
      vector<vector<int>>gp(n+1);
      for(int i =0; i<m;i++){
        int a,b; cin>>a>>b;
        gp[a].push_back(b);
      }
  vector<int>vis(n,0);
  stack<int>stk;
    for(int i =0;i<n;i++){
        if(!vis[i]){
            dfs(i,vis,gp,stk);
        }
    }  
    vector<int>ans;
    while(!stk.empty()){
        ans.push_back(stk.top()); stk.pop();
    }
    for(auto v: ans) cout<<v<<" ";
}
