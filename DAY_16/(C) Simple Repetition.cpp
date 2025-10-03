#include <bits/stdc++.h>
using namespace std;
 
bool check_prime(long long n) {
    if (n < 2) return false;
    if (n == 2) return true;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
 
int main() {
    int t; cin >> t;
    while (t--) {
        long long x, k;
        cin >> x >> k;
 
        string num = to_string(x);
        string num2 = "";
        for (int i = 0; i < k; i++) num2 += num;
        long long digit;
        try {
            digit = stoll(num2);
        } catch (...) {
            cout << "No" << endl; 
            continue;
        }
 
        if (check_prime(digit)) cout << "YES\n";
        else cout << "No\n";
    }
}
