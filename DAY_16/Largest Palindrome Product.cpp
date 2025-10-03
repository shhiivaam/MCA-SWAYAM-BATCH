class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) return 9; 
        int upper = pow(10, n) - 1; 
        int lower = upper / 10 + 1; 
        for (int i = upper; i >= lower; --i) {
            long long candidate = buildPalindrome(i);
            for (long long j = upper; j * j >= candidate; --j) {
                if (candidate % j == 0 && candidate / j <= upper) {
                    return candidate % 1337;
                }
            }
        }
        return -1; 
    }
private:
    long long buildPalindrome(int half) {
        string s = to_string(half);
        reverse(s.begin(), s.end());
        return stoll(to_string(half) + s);
    }
};
