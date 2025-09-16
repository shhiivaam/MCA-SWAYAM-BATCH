class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st;
        for (int num : nums) {
            st.push_back(num);
            while (st.size() >= 2) {
                int x = st.back(); st.pop_back();
                int y = st.back(); st.pop_back();
                int g = __gcd(x, y);
                if (g > 1) {
                    long long lcm = (long long)x * y / g;
                    st.push_back(lcm);
                } else {
                    st.push_back(y);
                    st.push_back(x);
                    break;
                }
            }
        }
        return st;
    }
};

