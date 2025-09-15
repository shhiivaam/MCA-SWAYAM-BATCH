#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    long long ans = 0;
    for(int bit = 0; bit < 30; bit++) {
        long long subcnt = 0;
        long long size = 0;
        for(int i = 0; i < n; i++) {
            if((nums[i] >> bit) & 1) {
                subcnt++;
            } else {
                if(subcnt > 0) {
                    size += subcnt * (subcnt + 1) / 2;
                    subcnt = 0;
                }
            }
        }
        if(subcnt > 0) {
            size += subcnt * (subcnt + 1) / 2;
        }
        ans += size * (1LL << bit);
    }
    cout << ans << "\n";
    return 0;
}
