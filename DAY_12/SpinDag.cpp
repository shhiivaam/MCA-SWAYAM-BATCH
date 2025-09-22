#include<iostream>
#include<stack>
#include<vector>
using namespace std;
void dfs(int node,vector<vector<pair<int,int>>>gp,vector<int>&vis,stack<int>&st){
    vis[node]=1;
    for(auto v : gp[node]){
        int  a = v.first;
        if(!vis[a]){
            dfs(a,gp,vis,st);
        }
    }
    st.push(node);
}
int main(){
    int n,m; cin>>n>>m;
    vector<vector<pair<int,int>>>gp(n);
    for(int i=0;i<m;i++){
        int a; cin>>a;
        int b; cin>>b;
        int d; cin>>d;
        gp[a].push_back({b,d});
    }
    vector<int>vis(n,0);
    stack<int>st;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,gp,vis,st);
        }
    }
    vector<int>dist(n);
    for(int i=0;i<n;i++) dist[i] = 1e9;
    dist[0]=0;
    while(!st.empty()){
        int node = st.top(); st.pop();
        for(auto v : gp[node]){
            int u = v.first;
            int wt = v.second;
            if(dist[node] + wt < dist[u]){
                dist[u] = dist[node] + wt;
            }
        }
    }
    for(auto a : dist) cout<<a<<" ";    
}
