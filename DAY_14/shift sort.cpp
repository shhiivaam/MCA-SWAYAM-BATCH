#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    size_t first_one = s.find('1');
    size_t last_zero = s.rfind('0');

    if (first_one == string::npos || last_zero == string::npos || first_one > last_zero) {
        cout << 0 << endl;
        return;
    }
    size_t first_11 = s.find("11");
    size_t last_00 = s.rfind("00");

    if (first_11 != string::npos && last_00 != string::npos && first_11 < last_00) {
        cout << 2 << endl;
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
