/*
Author : shhiivaam
*/
#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    vector<pair<int, int>> ops;
    for (int i = 0; i < n; ++i) {
        if (a[i] > b[i]) {
            swap(a[i], b[i]);
            ops.push_back({3, i + 1});
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        for (int j = min_idx; j > i; --j) {
            swap(a[j], a[j - 1]);
            ops.push_back({1, j});
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (b[j] < b[min_idx]) {
                min_idx = j;
            }
        }   
        for (int j = min_idx; j > i; --j) {
            swap(b[j], b[j - 1]);
            ops.push_back({2, j});
        }
    }
    cout << ops.size() << "\n";
    for (const auto& op : ops) {
        cout << op.first << " " << op.second << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

