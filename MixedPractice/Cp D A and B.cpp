#include <bits/stdc++.h>
using namespace std;

long long calculateMinSwaps(const string &inputString, char charToGroup) {
    vector<int> positions;
    for (int i = 0; i < inputString.size(); i++) {
        if (inputString[i] == charToGroup) {
            positions.push_back(i);
        }
    }
    
    if (positions.size() <= 1) {
        return 0;  
    }

    for (int i = 0; i < positions.size(); i++) {
        positions[i] -= i;
    }
    
    int median = positions[positions.size() / 2];
    
    long long swapCount = 0; 
    for (int val : positions) {
        swapCount += abs(static_cast<long long>(val) - median);
    }
    
    return swapCount;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    cout << min(calculateMinSwaps(s, 'a'),
                calculateMinSwaps(s, 'b')) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;
    while (testCases--) {
        solve();
    }
}
