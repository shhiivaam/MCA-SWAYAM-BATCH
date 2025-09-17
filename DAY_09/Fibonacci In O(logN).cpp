#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
struct Matrix {
    ll a[2][2];
    Matrix operator*(const Matrix& other) const {
        Matrix res{};
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                res.a[i][j] = 0;
                for (int k = 0; k < 2; k++) {
                    res.a[i][j] = (res.a[i][j] + a[i][k] * other.a[k][j]) % MOD;
                }
            }
        }
        return res;
    }
};
Matrix mat_pow(Matrix base, long long n) {
    Matrix res = {{{1, 0}, {0, 1}}};
    while (n > 0) {
        if (n & 1) res = res * base;
        base = base * base;
        n >>= 1;
    }
    return res;
}
ll fibonacci(long long n) {
    if (n == 0) return 0;
    Matrix base = {{{1, 1}, {1, 0}}};
    Matrix res = mat_pow(base, n-1);
    return res.a[0][0];
}
int main() {
    long long n;
    cin >> n;
    cout << fibonacci(n) << "\n";
}
