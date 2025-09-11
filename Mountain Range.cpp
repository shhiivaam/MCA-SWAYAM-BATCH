#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
vector<int> tree;
int n_segtree;
void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
        tree[node] = val;
        return;
    }
    int mid = start + (end - start) / 2;
    if (start <= idx && idx <= mid) {
        update(2 * node, start, mid, idx, val);
    } else {
        update(2 * node + 1, mid + 1, end, idx, val);
    }
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}
 
int query(int node, int start, int end, int l, int r) {
    if (r < start || end < l || l > r) {
        return 0;
    }
    if (l <= start && end <= r) {
        return tree[node];
    }
    int mid = start + (end - start) / 2;
    int p1 = query(2 * node, start, mid, l, r);
    int p2 = query(2 * node + 1, mid + 1, end, l, r);
    return max(p1, p2);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n;
    cin >> n;
 
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
 
    vector<long long> h(n);
    vector<pair<long long, int>> sorted_h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
        sorted_h[i] = {h[i], i};
    }
 
    vector<int> L(n), R(n);
    stack<int> s;
 
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && h[s.top()] <= h[i]) {
            s.pop();
        }
        L[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }
 
    while (!s.empty()) s.pop();
 
    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && h[s.top()] <= h[i]) {
            s.pop();
        }
        R[i] = s.empty() ? n : s.top();
        s.push(i);
    }
 
    sort(sorted_h.begin(), sorted_h.end());
 
    n_segtree = n;
    tree.assign(4 * n_segtree, 0);
    int max_len = 0;
 
    for (int k = 0; k < n; ++k) {
        int i = sorted_h[k].second;
 
        int max_left = query(1, 0, n - 1, L[i] + 1, i - 1);
        int max_right = query(1, 0, n - 1, i + 1, R[i] - 1);
        
        int current_dp = 1 + max(max_left, max_right);
        update(1, 0, n - 1, i, current_dp);
        max_len = max(max_len, current_dp);
    }
    cout << max_len << endl;
    return 0;
}
