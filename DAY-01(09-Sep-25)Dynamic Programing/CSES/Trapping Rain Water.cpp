/*
Author : shhiivaam
 */
class Solution {
public:
    vector<int> leftMemo, rightMemo;
    vector<int> *h;
    int n;
    int getLeftMax(int i) {
        if (i == 0) return (*h)[0];
        if (leftMemo[i] != -1) return leftMemo[i];
        return leftMemo[i] = max((*h)[i], getLeftMax(i - 1));
    }
    int getRightMax(int i) {
        if (i == n - 1) return (*h)[n - 1];
        if (rightMemo[i] != -1) return rightMemo[i];
        return rightMemo[i] = max((*h)[i], getRightMax(i + 1));
    }
    int trap(vector<int>& height) {
        n = height.size();
        h = &height;
        leftMemo.assign(n, -1);
        rightMemo.assign(n, -1);
        int water = 0;
        for (int i = 0; i < n; i++) {
            int left = getLeftMax(i);
            int right = getRightMax(i);
            water += min(left, right) - height[i];
        }
        return water;
    }
};
