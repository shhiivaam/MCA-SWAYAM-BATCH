class Solution {
public:
    int largestRectangleArea(vector<int>& he) {
        int n = he.size();
        stack<int> st;
        int max_area = 0;
        for (int i = 0; i <= n; i++) {
            int curHeight = (i == n ? 0 : he[i]);
            while (!st.empty() && curHeight < he[st.top()]) {
                int height = he[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                max_area = max(max_area, height * width);
            }
            st.push(i);
        }
        return max_area;
    }
};
