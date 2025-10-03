#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
void solve() {
    long long n;
    int m;
    cin >> n >> m;
    vector<long long> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }
    bool is_arithmetic_progression = true;
    for (int i = 1; i < m; ++i) {
        if (a[i] != a[i - 1] + 1) {
            is_arithmetic_progression = false;
            break;
        }
    }
    if (is_arithmetic_progression) {
        cout << n - a[m - 1] + 1 << endl;
    } else {
        cout << 1 << endl;
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
