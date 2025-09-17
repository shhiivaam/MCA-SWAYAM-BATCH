class Solution {
public:
    const int mod = 1e9 + 7;
    long long dp[35][1005];
    long long solve(int n, int k, int tar) {
        if (n == 0) return (tar == 0); 
        if (tar < 0) return 0;      
        if (dp[n][tar] != -1) return dp[n][tar];

        long long ans = 0;
        for (int face = 1; face <= k; face++) {
            ans = (ans + solve(n - 1, k, tar - face)) % mod;
        }
        return dp[n][tar] = ans;
    }

    int numRollsToTarget(int n, int k, int target) {
        memset(dp, -1, sizeof(dp));
        return solve(n, k, target);
    }
};

