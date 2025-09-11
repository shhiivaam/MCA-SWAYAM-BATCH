#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[205][205];
    int rec(int l, int r, vector<int>& arr) {
        if (l + 1 == r) return 0;

        if (dp[l][r] != -1) return dp[l][r];

        int ans = 1e9;
        for (int mid = l + 1; mid < r; mid++) {
            int cost = rec(l, mid, arr) + rec(mid, r, arr) 
                       + arr[l] * arr[mid] * arr[r];
            ans = min(ans, cost);
        }
        return dp[l][r] = ans;
    }

    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        memset(dp, -1, sizeof(dp));
        return rec(0, n - 1, arr);
    }
};
