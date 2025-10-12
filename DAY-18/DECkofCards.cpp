#include <iostream>
#include <string>
#include <vector>
#include <numeric>
 
// This function encapsulates the logic for a single test case.
void solve() {
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;
 
    // Edge Case: If n equals k, all cards are removed from the deck.
    // The final deck is empty, so every card's fate is 'removed'.
    if (n == k) {
        for (int i = 0; i < n; ++i) {
            std::cout << '-';
        }
        std::cout << "\n";
        return;
    }
 
    int remove_top_fixed = 0;   
    int remove_bottom_fixed = 0; 
    int remove_choice = 0;   
    
    for (char action : s) {
        if (action == '0') {
            remove_top_fixed++;
        } else if (action == '1') {
            remove_bottom_fixed++;
        } else {
            remove_choice++;
        }
    }

    int union_start = remove_top_fixed + 1;
    int union_end = n - remove_bottom_fixed;
    int intersection_start = remove_top_fixed + remove_choice + 1;
    int intersection_end = n - (remove_bottom_fixed + remove_choice);
     std::string result;
    result.reserve(n);
    for (int i = 1; i <= n; ++i) {
        if (i >= intersection_start && i <= intersection_end) {
            result += '+';
        } 
       
        else if (i >= union_start && i <= union_end) {
            result += '?';
        } 
      
        else {
            result += '-';
        }
    }
    std::cout << result << "\n";
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