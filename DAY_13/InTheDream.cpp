#include <bits/stdc++.h>
using namespace std;
bool is_half_possible(int score1, int score2) {
    if (score1 > 2 * score2 + 2) {
        return false;
    }
    if (score2 > 2 * score1 + 2) {
        return false;
    }
    return true;
}

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    bool first_half_ok = is_half_possible(a, b);
    int second_half_a_goals = c - a;
    int second_half_b_goals = d - b;
    bool second_half_ok = is_half_possible(second_half_a_goals, second_half_b_goals);
    if (first_half_ok && second_half_ok) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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
