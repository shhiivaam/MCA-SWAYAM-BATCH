#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int Rec(int level, vector<int>& height, vector<int>& dp) {
        if (level == height.size() - 1) return 0;
        if (dp[level] != -1) return dp[level];

        int oneStep = Rec(level + 1, height, dp) + abs(height[level] - height[level + 1]);

        int twoStep = INT_MAX;
        if (level + 2 < height.size()) {
            twoStep = Rec(level + 2, height, dp) + abs(height[level] - height[level + 2]);
        }

        return dp[level] = min(oneStep, twoStep);
    }

    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n, -1);
        return Rec(0, height, dp);
    }
};
int main() {
    Solution sol;
    vector<int> height = {10, 30, 40, 20};
    int result = sol.minCost(height);
    cout << "Minimum cost to reach end: " << result << endl;

    return 0;
}
