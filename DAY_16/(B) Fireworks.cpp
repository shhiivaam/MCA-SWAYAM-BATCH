#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t; 
    cin >> t;
    while (t--) {
        long long a, b, m;
        cin >> a >> b >> m;
 
        long long c = m / a + 1;
        long long d = m / b + 1;
 
        cout << c + d << "\n";
    }
    return 0;
}
