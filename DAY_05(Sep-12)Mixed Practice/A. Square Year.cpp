#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void solve() {
    string s;
    cin >> s;

    int year = stoi(s);

    for (int i = 1; i < 4; ++i) {
        string part1_str = s.substr(0, i);
        string part2_str = s.substr(i);

        int a = stoi(part1_str);
        int b = stoi(part2_str);

        if ((long long)(a + b) * (a + b) == year) {
            cout << a << " " << b << endl;
            return;
        }
    }

    cout << -1 << endl;
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
