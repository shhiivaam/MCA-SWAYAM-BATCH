#include<iostream>
using namespace std;
vector<int>vis;
vector<vector<int>>gp;
vector<int>comp;
vector<int>cmp_size;
void dfs(int node,int cmp){      
    vis[node]=1;
    comp[node]=cmp;
    cmp_size[cmp]++;
    for(auto v : gp[node]){
        if(!vis[v])
        dfs(v,cmp);
    }
}
int main(){
  int n,m; cin>>n>>m;
  gp.resize(n+1);
  vis.resize(n+1);
  comp.resize(n+1);
  cmp_size.resize(n+1);
  for(int i = 0; i<m;i++){
    int a,b;  cin>>a>>b;
    gp[a].push_back(b);
    gp[b].push_back(a);
  }   
  int cmpno=1;
 for(int i =1; i<=n;i++){
    if(!vis[i]){
      dfs(i,cmpno);
      cmpno++;
    }
 }
  int q; cin>>q;
 while(q--){
    int a,b; cin>>a>>b;
    if(comp[a] == comp[b])
     cout<<"Connected\n";
    else
    cout<<"Nope\n"; 
 } 
}
