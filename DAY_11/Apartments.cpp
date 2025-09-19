#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> stu(n), apr(m);
    for (int i = 0; i < n; i++) cin >> stu[i];
    for (int i = 0; i < m; i++) cin >> apr[i];

    sort(stu.begin(), stu.end());
    sort(apr.begin(), apr.end());

    int i = 0, j = 0, maxi = 0;

    while (i < n && j < m) {
        if (abs(stu[i] - apr[j]) <= k) {
            maxi++;
            i++;
            j++;
        } else if (stu[i] > apr[j] + k) {
            j++;
        } else {
            i++;
        }
    }

    cout << maxi << "\n";
}
