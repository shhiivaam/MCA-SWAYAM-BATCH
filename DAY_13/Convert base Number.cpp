#include <bits/stdc++.h>
using namespace std;
int charToVal(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    return c - 'A' + 10;
}
char valToChar(int v) {
    if (v < 10) return '0' + v;
    return 'A' + (v - 10);
}
long long toDecimal(string N, int A) {
    long long result = 0;
    for (char c : N) {
        result = result * A + charToVal(c);
    }
    return result;
}
string fromDecimal(long long num, int B) {
    if (num == 0) return "0";
    string res = "";
    while (num > 0) {
        int rem = num % B;
        res.push_back(valToChar(rem));
        num /= B;
    }
    reverse(res.begin(), res.end());
    return res;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        string N;
        int A, B;
        cin >> N >> A >> B;
        long long decimalVal = toDecimal(N, A);
        string ans = fromDecimal(decimalVal, B);
        cout << ans << endl;
    }
    return 0;
}
