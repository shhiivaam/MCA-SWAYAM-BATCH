#include<bits/stdc++.h>
using namespace std;
int Solve(int i , int j,int n,int m,vector<vector<int>>&mtx,vector<vector<int>>&dp){
    //base case
    if(i == n-1 && j == m-1) return mtx[i][j];
    if(i >= n || j >= m) return 0;

     if(dp[i][j] != -1) return dp[i][j];

	//Two option move karne ka either right ot down
    //transition
	int right = mtx[i][j] + Solve(i,j+1,n,m,mtx,dp);
	int down = mtx[i][j] + Solve(i+1,j,n,m,mtx,dp);

	int cc =  max(right,down);
	return dp[i][j] = cc;
}
int main(){
	int n,m; cin>>n>>m;
	vector<vector<int>>mtx(n,vector<int>(m,0));
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			cin>>mtx[i][j];
		}
	}
	vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
	int ans = Solve(0,0,n,m,mtx,dp);
	cout<<ans;
}
