class Solution {
  public:
    vector<int> factorial(int n) {
        vector<int> result;
        result.push_back(1);
        for (int x = 2; x <= n; x++) {
            int carry = 0;
            for (int i = result.size() - 1; i >= 0; i--) {
                int prod = result[i] * x + carry;
                result[i] = prod % 10;
                carry = prod / 10;
            }
            while (carry) {
                result.insert(result.begin(), carry % 10);
                carry /= 10;
            }
        }
        return result;
    }
};
