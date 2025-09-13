#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> current_counts(10, 0);
    int result = 0;

    for (int i = 0; i < n; ++i) {
        current_counts[a[i]]++;
        if (current_counts[0] >= 3 &&
            current_counts[1] >= 1 &&
            current_counts[2] >= 2 &&
            current_counts[3] >= 1 &&
            current_counts[5] >= 1) {
            
            result = i + 1;
            break; 
        }
    }
    cout << result << endl;
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
