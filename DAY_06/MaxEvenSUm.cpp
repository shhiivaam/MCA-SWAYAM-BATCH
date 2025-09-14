#include <iostream>
using namespace std;

void solve() {
    long long a, b;
    cin >> a >> b;

    bool a_is_odd = (a % 2 != 0);
    bool b_is_odd = (b % 2 != 0);

    if (a_is_odd && b_is_odd) {
        cout << a * b + 1 << endl;
    } else if (!a_is_odd && b_is_odd) {
        cout << -1 << endl;
    } else { 
        if (!a_is_odd) {
            cout << a * (b / 2) + 2 << endl;
        } else { 
            if (b % 4 == 0) {
                cout << a * (b / 2) + 2 << endl;
            } else {
                cout << -1 << endl;
            }
        }
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
