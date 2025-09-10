#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0; i<n; i++) cin>>arr[i];

    vector<int>lis;
    for(int i = 0; i < n; i++){
        if(lis.empty() || lis.back() < arr[i]){
            lis.push_back(arr[i]);
        }else{
            auto it = lower_bound(arr.begin(),arr.end(),arr[i]);
            *it = arr[i];
        }
       cout<<i<<": ";
       for(auto v : lis){
          cout<<v<<" ";
       } 
       cout<<endl;
    }    
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
