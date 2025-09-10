/*
Author : shhiivaam
*/
class Solution {
public:
    vector<int> dp;
    int Solve(long long n) {
        if (n == 1)
            return 0;
        if (n < dp.size() && dp[n] != -1)
            return dp[n];
        int res;
        if (n % 2 == 0)
            res = 1 + Solve(n / 2);
        else
            res = 1 + Solve(3 * n + 1);
        if (n < dp.size())
            dp[n] = res;
        return res;
    }
    int getKth(int lo, int hi, int k) {
        dp.assign(1000000, -1);
        vector<pair<int, int>> v;
        for (int i = lo; i <= hi; i++) {
            int pwr = Solve(i);
            v.push_back({pwr, i});
        }
        sort(v.begin(), v.end(), [](auto& a, auto& b) {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first < b.first;
        });
        return v[k - 1].second;
    }
};
