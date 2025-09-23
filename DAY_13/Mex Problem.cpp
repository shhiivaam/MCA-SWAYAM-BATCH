#include <bits/stdc++.h>
using namespace std;

int maxMEX(vector<int>& arr, int K) {
    unordered_map<int,int> freq;
    for (int x : arr) {
        freq[x % K]++; 
    }
    
    int mex = 0;
    while (true) {
        int rem = mex % K;
        if (freq[rem] > 0) {
            freq[rem]--;
            mex++;
        } else {
            break;
        }
    }
    return mex;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];
        
        cout << maxMEX(arr, K) << "\n";
    }
    return 0;
}
