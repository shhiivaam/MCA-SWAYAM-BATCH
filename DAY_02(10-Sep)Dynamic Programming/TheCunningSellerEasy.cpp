/*
Author : shhiivaam
*/
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
void solve() {
    ll n;
    cin >> n;
    ll total_cost = 0;
    vector<ll> p3(21);
    p3[0] = 1;
    for (int i = 1; i <= 20; ++i) {
        p3[i] = p3[i-1] * 3;
    }
    for (int x = 0; n > 0; ++x) {
        int digit = n % 3;

        if (digit != 0) {
            ll cost_per_deal;
            if (x == 0) {
                cost_per_deal = 3;
            } else {
                cost_per_deal = p3[x + 1] + (ll)x * p3[x - 1];
            }
            total_cost += (ll)digit * cost_per_deal;
        }
        n /= 3;
    }

    cout << total_cost << std::endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
