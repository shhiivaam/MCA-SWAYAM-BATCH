#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void solve() {
    long long n;
    cin >> n;

    set<long long> solutions;
  
    long long power_of_10 = 10;
    while (true) {
        long long divisor = power_of_10 + 1;
        if (divisor > n) {
            break;
        }

        if (n % divisor == 0) {
            solutions.insert(n / divisor);
        }
        power_of_10 *= 10;
    }

    if (solutions.empty()) {
        cout << 0 << endl;
    } else {
        cout << solutions.size();
        for (long long x : solutions) {
            cout << " " << x;
        }
        cout << endl;
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
