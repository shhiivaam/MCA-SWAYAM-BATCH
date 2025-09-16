#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long floordiv(long long a, long long b) {
        long long q = a / b;
        long long r = a % b;
        if ((r != 0) && ((a < 0) ^ (b < 0))) {
            q -= 1;
        }
        return q;
    }
    int evaluatePostfix(vector<string>& arr) {
        stack<long long> st;
        for (int i = 0; i < arr.size(); i++) {
            if (isdigit(arr[i][0]) || (arr[i].size() > 1 && arr[i][0] == '-')) {
                long long num = stoll(arr[i]);
                st.push(num);
            } else {
                if (st.size() >= 2) {
                    long long b = st.top(); st.pop();
                    long long a = st.top(); st.pop();
                    if (arr[i] == "*") {
                        st.push(a * b);
                    } else if (arr[i] == "/") {
                        st.push(floordiv(a, b));
                    } else if (arr[i] == "^") {
                        st.push(pow(a, b));
                    } else if (arr[i] == "+") {
                        st.push(a + b);
                    } else if (arr[i] == "-") {
                        st.push(a - b);
                    } else if (arr[i] == "%") {
                        st.push(a % b);
                    }
                }
            }
        }
        return st.top();
    }
};
