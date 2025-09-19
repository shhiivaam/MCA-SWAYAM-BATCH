#include <iostream>
using namespace std;
 
void solve() {
    long long a1, a2, a4, a5;
    cin >> a1 >> a2 >> a4 >> a5;
    long long val_for_cond1 = a1 + a2;
    long long val_for_cond2 = a4 - a2;
    long long val_for_cond3 = a5 - a4;
    if (val_for_cond1 == val_for_cond2 && val_for_cond2 == val_for_cond3) {
        cout << 3 << "\n";
    } else if (val_for_cond1 == val_for_cond2 || val_for_cond1 == val_for_cond3 || val_for_cond2 == val_for_cond3) {
        cout << 2 << "\n";
    } else {
        cout << 1 << "\n";
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
