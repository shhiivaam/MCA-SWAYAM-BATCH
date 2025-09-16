#include <bits/stdc++.h>
using namespace std;
struct BIT {
    vector<int> tree;
    int n;
    BIT(int size) {
        n = size;
        tree.assign(n + 1, 0);
    }
    void update(int idx, int val) {
        while (idx <= n) {
            tree[idx] += val;
            idx += idx & -idx;
        }
    }
    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += tree[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
    int findKth(int k) {
        int l = 1, r = n, ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (query(mid) >= k) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> arr(N + 1), pos(N + 1);
        for (int i = 1; i <= N; i++) cin >> arr[i];
        for (int i = 1; i <= N; i++) cin >> pos[i];
        BIT bit(N);
        for (int i = 1; i <= N; i++) bit.update(i, 1);
        for (int i = 1; i <= N; i++) {
            int k = pos[i];
            int idx = bit.findKth(k);
            cout << arr[idx] << " ";
            bit.update(idx, -1); 
        }
        cout << "\n";
    }

    return 0;
}
