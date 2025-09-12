#include<iostream>
#include<string>
using namespace std;
void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> first(26, n); // first occurrence of each door
    vector<int> last(26, -1); // last occurrence of each door

    // Compute first and last positions
    for (int i = 0; i < n; i++) {
        int d = s[i] - 'A';
        first[d] = min(first[d], i);
        last[d] = max(last[d], i);
    }

    int open_doors = 0;
    vector<bool> is_open(26, false);

    for (int i = 0; i < n; i++) {
        int d = s[i] - 'A';

        if (i == first[d]) {
            open_doors++;
            is_open[d] = true;
            if (open_doors > k) {
                cout << "YES\n";
                return;
            }
        }

        if (i == last[d]) {
            open_doors--;
        }
    }

    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
