#include <iostream>
#include <vector>
#include <numeric>
 
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long long d = a[1] - a[0];
    for (int i = 2; i < n; ++i) {
        if (a[i] - a[i - 1] != d) {
            cout << "NO" << endl;
            return;
        }
    }
    long long numerator_y = a[0] - d;
    if (numerator_y < 0 || numerator_y % (n + 1) != 0) {
        cout << "NO" << endl;
        return;
    }
    long long numerator_x = a[0] + 1LL * n * d;
    if (numerator_x < 0) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
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
