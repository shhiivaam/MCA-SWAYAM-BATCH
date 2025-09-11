#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll INF = 1e18;
ll rec(ll idx, ll valueLeft,
       vector<ll> &weights, vector<ll> &values,
       vector<vector<ll>> &dp,ll n) {
    if (valueLeft == 0) return 0; 
    if (idx == n) return INF; 

    if (dp[idx][valueLeft] != -1) return dp[idx][valueLeft];

    
    ll notTake = rec(idx + 1, valueLeft, weights, values, dp,,n);

    
    ll take = INF;
    if (values[idx] <= valueLeft) {
        take = weights[idx] + rec(idx + 1, valueLeft - values[idx], weights, values, dp,n);
    }

    return dp[idx][valueLeft] = min(take, notTake);
}

int main() {
    ll n, maxWeight;
    cin >> n >> maxWeight;
    vector<ll> weights(n), values(n);
    for (ll i = 0; i < n; i++) cin >> weights[i] >> values[i];
    
    ll maxValue = 0;
    for (ll v : values) maxValue += v;

    vector<vector<ll>> dp(n + 1, vector<ll>(maxValue + 1, -1));

     ll ans = rec(0,)  cout << ans << "\n";
    return 0;
}
