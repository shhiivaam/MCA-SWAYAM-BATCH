#include <bits/stdc++.h>
using namespace std;
 
#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<
 
#define INF (ll)1e18
#define mod 998244353
#define maxn 110
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif
 
    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<ll> v;
        for (ll i = 0; i < 2 * n; i++) {
            ll x; cin >> x; v.pb(x);
        }
 
        vector<ll> ans(n + 3, 0);
        for (ll i = 0; i < 2 * n; i += 2) ans[1] -= v[i];
        for (ll i = 1; i < 2 * n; i += 2) {
            ans[1] += v[i]; ans[2] -= v[i];
        }
        for (ll i = 2; i < 2 * n; i += 2) ans[2] += v[i];
        ans[2] += 2 * v.back() - v[0];
 
        for (ll i = 3; i <= n; i++) {
            ans[i] = ans[i - 2] + 2 * (v[(ll)v.size() - i + 1] - v[i - 2]);
        }
 
        for (ll i = 1; i <= n; i++) cout << ans[i] << ' ';
        cout << nl;
    }
 
    return 0;
}
