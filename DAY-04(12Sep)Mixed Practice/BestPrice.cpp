/*
    Author: shhiivaam
    Problem: E - Best Price (Codeforces)
    Complexity: O(n log n)
*/

#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);

void solve() {
    int n;
    long long k;
    cin >> n >> k;

    vector<long long> a(n), b(n), cand;
    cand.reserve(2 * n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cand.push_back(a[i]);
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        cand.push_back(b[i]);
    }

    sort(cand.begin(), cand.end());
    cand.erase(unique(cand.begin(), cand.end()), cand.end());

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    long long ans = 0;

    for (long long p : cand) {
        auto itB = lower_bound(b.begin(), b.end(), p);
        long long buyers = b.end() - itB;
        if (buyers == 0) continue;

        auto itA = lower_bound(a.begin(), a.end(), p);
        long long happy = a.end() - itA;
        long long unhappy = buyers - happy;

        if (unhappy <= k) {
            ans = max(ans, p * buyers);
        }
    }

    cout << ans << "\n";
}

int main() {
    fast_io;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
