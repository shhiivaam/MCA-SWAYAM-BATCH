#include <iostream>
#include <vector>
#include <numeric>
 
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
 
    long long surplus = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > b[i]) {
            surplus += (a[i] - b[i]);
        }
    }
 
    cout << surplus + 1 << endl;
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
