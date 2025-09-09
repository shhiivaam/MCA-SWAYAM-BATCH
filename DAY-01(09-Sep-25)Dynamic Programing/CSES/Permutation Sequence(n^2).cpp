/*
Author : shhiivaam
*/
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums(n), fact(n);
        for(int i = 0; i < n; i++) nums[i] = i + 1;
        fact[0] = 1;
        for(int i = 1; i < n; i++) fact[i] = fact[i-1] * i;
        k--;
        string ans = "";
        for(int i = n; i >= 1; i--) {
            int idx = k / fact[i-1];
            ans += to_string(nums[idx]);
            nums.erase(nums.begin() + idx);
            k %= fact[i-1];
        }

        return ans;
    }
};
