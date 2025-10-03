#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <functional> 
void solve() {
    int n;
    std::cin >> n;
    long long sum_evens = 0;
    std::vector<long long> odds;
    for (int i = 0; i < n; ++i) {
        long long a;
        std::cin >> a;
        if (a % 2 == 0) {
            sum_evens += a;
        } else {
            odds.push_back(a);
        }
    }
    if (odds.empty()) {
        std::cout << 0 << "\n";
        return;
    }
    std::sort(odds.begin(), odds.end(), std::greater<long long>());
    long long sum_odds_cut = 0;
    int k = odds.size();
    int num_odds_to_cut = (k + 1) / 2; 
    for (int i = 0; i < num_odds_to_cut; ++i) {
        sum_odds_cut += odds[i];
    }
    long long total_cut = sum_evens + sum_odds_cut;
    std::cout << total_cut << "\n";
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
