#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll inf = 1e9;
const ll M = 1000000007;

void solve()
{
    // Write code here
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        for (int j = 0; j < 4; j++)
        {
            arr.push_back(x);
        }
    }
    sort(arr.begin(), arr.end());
    vector<int> jobs;
    for (int i = 0; i < 4 * n; i++)
    {
        ll x;
        cin >> x;
        jobs.push_back(x);
    }
    sort(jobs.begin(), jobs.end(), greater<int>());
    int ans = 0;
    vector<int> times(4 * n, 0);
    for (int i = 0; i < 4 * n; i++)
    {
        times[i] = jobs[i] + arr[i];
    }
    ans = *max_element(times.begin(), times.end());
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
