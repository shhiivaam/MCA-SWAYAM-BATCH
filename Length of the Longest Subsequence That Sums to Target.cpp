class Solution {
public:
    int solve(int idx, vector<int>& nums, int tar, vector<vector<int>>& dp) {
        if (tar == 0) return 0;             
        if (idx < 0) return -1e9;           
        if (dp[idx][tar] != -1) return dp[idx][tar];
        int notTake = solve(idx - 1, nums, tar, dp);
        int take = -1e9;
        if (tar >= nums[idx]) {
            int res = solve(idx - 1, nums, tar - nums[idx], dp);
            if (res != -1e9) take = 1 + res;
        }
        return dp[idx][tar] = max(notTake, take);
    }

    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        int ans = solve(n - 1, nums, target, dp);
        return (ans < 0 ? -1 : ans);
    }
};
