class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        long long total = 1LL * n * (n + 1) / 2;
        long long sum = 0;
        for (int i = 0; i < n; i++) sum += arr[i];
        sort(arr.begin(), arr.end());
        int repeating = -1;
        for (int i = 1; i < n; i++) {
            if (arr[i] == arr[i - 1]) {
                repeating = arr[i];
                break;
            }
        }
        long long missing = total - (sum - repeating);
        return {repeating, (int)missing};
    }
};
