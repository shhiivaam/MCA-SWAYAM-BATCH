#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using ld = long double;
const int maxN = 100001;
const int INF = 1e15;
const int MOD = 998244353;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rnd(int b){
  return (unsigned long long)rng()%b;
}
vector<int>g(maxN+1,0);
vector<int>h(maxN+1,0);
vector<int>k(maxN+1);
vector<int> solve(int m){
  if(m==2){
    return {1,2};
  }
  if(m==3){
    return {1,2,4,1};
  }
  if(m==4){
    return {5,6,8,5,1,6};
  }
  if(m==5){
    return {5,6,8,5,1,6,12,1};
  }
  
  if(m==6){
    return {17,18,22, 17,11,18,10,1,11, 22,10};
  }
  if(m==7){
    return {1,2,6,1,7,15,6,16,27,15,2,16,1,27};
  }
  /*if(m==8){
    vector<int>a = {11, 9, 4 ,11, 19, 9 ,20, 33 ,19 ,4 ,20, 37, 55, 33, 9 ,55,4};
    vector<int>b;
    for(auto u : a)b.push_back(56-u);
    return b;
  }*/
  int i = k[m];
  if(i==-1){
    return solve(m-1);
  }
  int t = (m-2*g[i]-h[i])/i;
  auto ans1 = solve(i);
 
  for(auto &u : ans1) u=u*32*t +1;
  vector<int>ans;
  ans.push_back(ans1[0]+8*(t-1));
  int isright = 1;
  for(int j = 1;j<ans1.size();j++){
    if(ans1[j-1] < ans1[j]){
      if(!isright){
        int step = abs(ans.back()- ans[ans.size()-2]);
        if(t>1){
          ans.push_back(ans.back()-step-1);
          ans.push_back(ans1[j-1]+8*(t-1));
        }
      }
      int l = ans1[j-1];
      int r = ans1[j];
      int li = t-1;
      int ri = 0;
      int mid = (l + 8*li + r+8*ri)/2 - 2;
      ans.push_back(mid+1);
      ans.push_back(r+8*ri);
      for(int jj = 1;jj<t;jj++){
        li--;
        ri++;
        ans.push_back(mid-1);
        ans.push_back(l+8*li);
        ans.push_back(mid+1);
        ans.push_back(r+8*ri);
      } // to the left of r
      isright = 1;
    }
    else{
      if(isright){
        int step = abs(ans.back()- ans[ans.size()-2]);
        if(t>1){
          ans.push_back(ans.back()+step+1);
          ans.push_back(ans1[j-1]);
        }
      }
      int l = ans1[j];
      int r = ans1[j-1];
      int li = t-1;
      int ri = 0;
      int mid = (l + 8*li + r+8*ri)/2 + 2;
      ans.push_back(mid-1);
      ans.push_back(l+8*li);
      for(int jj = 1;jj<t;jj++){
        li--;
        ri++;
        ans.push_back(mid+1);
        ans.push_back(r+8*ri);
        ans.push_back(mid-1);
        ans.push_back(l+8*li);
      } // to the left of l
      isright = 0;
    }
  }
 
  return ans;
}
signed main(){
  
  g[2] = 1;
  g[3] = 3;
  g[4] = 5;
  g[5] = 7;
  g[6] = 10;
  g[7] = 13;
  //g[8] = 16;
  
  h[2] = 0;
  h[3] = 1;
  h[4] = 2;
  h[5] = 3;
  h[6] = 5;
  h[7] = 8;
  //h[7] = 8;
 
 
  k[5] = 0;
  k[4] = 0;
  k[2] = 0;
  k[3] = 0;
  k[6] = 0;
  k[7] = 0;
  //k[8] = 0;
  
  for(int i = 2; i<=maxN;i++){
    if(g[i]<g[i-1]){
      g[i] = g[i-1];
      h[i] = h[i-1];
      k[i] = -1;
    }
    for(int t = 2;t*i+ 2*g[i] + h[i] <=maxN; t++){
      if(g[t*i+ 2*g[i]+h[i]]< (4*t-2)*g[i]+2*h[i]){
        g[t*i+ 2*g[i]+h[i]] = (4*t-2)*g[i]+2*h[i];
        k[t*i+ 2*g[i]+h[i]] =i;
        h[t*i+ 2*g[i]+h[i]] = (2*t-2)*g[i] + h[i];
      }
    }
  }
  int n;
  cin>>n;
  int m;
  cin>>m;
  if(m!=8) m = 15300;
  //cout<<g[m]<<" "<<k[m]<<endl;
  /*
  int v = m;
  while(v>7){
    while(k[v]==-1)v--;
    if(v<=7)break;
    cout<<v<<" "<<(v-2*g[k[v]]-h[k[v]])/k[v]<<endl;
    v = k[v];
  }cout<<endl;
  */
 
  auto a = solve(m);
  /*
  int ch = 1;
  for(int i =2;i<a.size();i++){
    ch &= (abs(a[i]-a[i-1]) > abs(a[i-1]-a[i-2]));
  }
 
  cout<<ch<<endl;
  cout<<a.size()<<endl;
  //for(auto u : a)cout<<u<< " ";
  //    cout<<endl;
  set<int>s;
  for(auto u : a)s.insert(u);
  cout<<s.size()<<endl;
  */
  assert(a.size()>=n);
    int mx = 0;
  for(int i = 0;i<n;i++)mx = min(mx,a[i]);
  for(int i = 0;i<n;i++)cout<<a[i]-mx<<" ";
    cout<<endl;
}
