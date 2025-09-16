#include<bits/stdc++.h>
using namespace std;
tuple<long long, long long, long long> make_state(long long a, long long b, long long c) {
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);
    return make_tuple(a, b, c);
}
void solve() {
    long long x;
    cin >> x;
 
    if (x == 0) {
        cout << 0 << endl;
        return;
    }
    queue<tuple<long long, long long, long long>> q;
    map<tuple<long long, long long, long long>, int> dist;
    tuple<long long, long long, long long> initial_state = make_tuple(0, 0, 0);
    q.push(initial_state);
    dist[initial_state] = 0;
    long long min_ans = -1;
    long long y = x / 2;
    if (get<0>(initial_state) >= y) {
        min_ans = 3; 
    }
 
    while (!q.empty()) {
        tuple<long long, long long, long long> current_state = q.front();
        q.pop();
 
        long long a = get<0>(current_state);
        long long b = get<1>(current_state);
        long long c = get<2>(current_state);
        int d = dist[current_state];
        if (min_ans != -1 && d + 1 >= min_ans) {
            continue;
        }
        vector<tuple<long long, long long, long long>> potential_next_states;
        long long next_val1 = min(x, 2 * b + 1);
        if (next_val1 > a) {
            potential_next_states.push_back(make_state(next_val1, b, c));
        }
        long long next_val2 = min(x, 2 * a + 1);
        if (next_val2 > b) {
            potential_next_states.push_back(make_state(a, next_val2, c));
        }
  
        if (next_val2 > c) {
            potential_next_states.push_back(make_state(a, b, next_val2));
        }
 
        for (const auto& next_s : potential_next_states) {
          
            if (dist.find(next_s) == dist.end()) {
                int next_d = d + 1;
                
                long long na = get<0>(next_s);
                long long nb = get<1>(next_s);
                long long nc = get<2>(next_s);
 
               
                if (na >= y) {
                    long long temp_ans = next_d;
                    if (na < x) temp_ans++;
                    if (nb < x) temp_ans++;
                    if (nc < x) temp_ans++;
                    if (min_ans == -1 || temp_ans < min_ans) {
                        min_ans = temp_ans;
                    }
                }
                
                
                if (min_ans != -1 && next_d >= min_ans) {
                    continue;
                }
 
                dist[next_s] = next_d;
                q.push(next_s);
            }
        }
    }
 
    cout << min_ans << endl;
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
