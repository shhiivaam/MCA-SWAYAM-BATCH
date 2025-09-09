/*
Author : shhiivaam
Difficulty : Hard
Topic : Dynamic Programing in Graphs
*/
class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp, int n, int m) {
        if (dp[i][j] != -1) return dp[i][j];
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        int best = 1; 
        for (int k = 0; k < 4; k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && matrix[nx][ny] > matrix[i][j]) {
                best = max(best, 1 + dfs(nx, ny, matrix, dp, n, m));
            }
        }
        return dp[i][j] = best;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, dfs(i, j, matrix, dp, n, m));
            }
        }
        return ans;
    }
};
