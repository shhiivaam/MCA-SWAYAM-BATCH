/*
Author : shhiivaam
*/
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<string>v(n);
    for(int i = 0;i<n;i++){
        cin>>v[i];
    }
    int min_opr=0;
    for(int i =0;i<n;i++){
        string temp = v[i];
        int s = 0;
        while(s < temp.length()-1){
            if(temp[s] == temp[s+1]){
                temp[s+1] = '-1';
                min_opr++;
            }
            s++;
        }
    }
    cout<<min_opr<<"\n";
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