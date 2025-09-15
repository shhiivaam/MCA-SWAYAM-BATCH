/*
Author : shhiivaam
*/
#include <bits/stdc++.h>
using namespace std;

void ans() {
    int n,k; cin>>n>>k;
    vector<int> v(n); 
    for(int i= 0;i<n;i++) cin>>v[i];

    sort(v.begin(),v.end());
    
    int curr_len = 1;
    int max_len = 1;

    for(int i = 1; i < n; i++){
        if(abs(v[i] - v[i-1]) <= k){
            curr_len++;
        } else {
            max_len = max(max_len, curr_len);
            curr_len = 1;
        }
    }
    max_len = max(max_len, curr_len); 
    cout << n - max_len << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        ans();
    }
    return 0;
}
