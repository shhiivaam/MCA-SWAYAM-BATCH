#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> freq(51, 0);
        int n = nums.size();
        int i = 0, j = 0;
        vector<int> ans;

        while (j < n) {
            freq[nums[j]]++;  
            j++;
            if (j - i == k) {
                vector<pair<int, int>> pairs;
                for (int val = 0; val <= 50; val++) {
                    if (freq[val] > 0)
                        pairs.push_back({freq[val], val});
                }
                sort(pairs.begin(), pairs.end(), [](auto &a, auto &b) {
                    if (a.first == b.first)
                        return a.second > b.second;
                    return a.first > b.first;
                });
                int sum = 0;
                for (int t = 0; t < min(x, (int)pairs.size()); t++) {
                    sum += pairs[t].first * pairs[t].second;
                }
                ans.push_back(sum);
                freq[nums[i]]--;
                i++;
            }
        }
        return ans;
    }
};
