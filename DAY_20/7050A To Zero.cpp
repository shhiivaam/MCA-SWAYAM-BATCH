#include <iostream>
void solve() {
    long long n, k;
    std::cin >> n >> k;

    long long operations = 0;
    if (n % 2 == 0) {
        long long divisor = k - 1;
        operations = (n + divisor - 1) / divisor;
    } else {
       
        operations = 1;
        long long remaining_n = n - k;
        if (remaining_n > 0) {
            long long divisor = k - 1;
            operations += (remaining_n + divisor - 1) / divisor;
        }
    }

    std::cout << operations << std::endl;
}

int main() {
   
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
