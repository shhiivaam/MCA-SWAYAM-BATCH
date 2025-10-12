#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
 
using namespace std;
 
void solve() {
    long long n;
    cin >> n;
    string s;
    cin >> s;
 
    long long ones_count = 0;
    for (char c : s) {
        if (c == '1') {
            ones_count++;
        }
    }
 
    long long zeros_count = n - ones_count;
 
    
    long long total_ones = ones_count * (n - 1) + zeros_count * 1;
 
    cout << total_ones << endl;
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
