#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to calculate the minimum changes required
int minChangesToAvoidConsecutive(const vector<string>& strings) {
  int total_changes = 0;

  for (const string& s : strings) {
    int changes = 0;
    string modified = s;

    for (int i = 1; i < modified.size(); ++i) {
      if (modified[i] == modified[i - 1]) {
        // Change the current character to avoid conflict
        modified[i] = '#';
        changes++;
      }
    }

    total_changes += changes;
  }

  return total_changes;
}

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> strings(n);

  for (int i = 0; i < n; ++i) {
    cin >> strings[i];
  }

  cout << minChangesToAvoidConsecutive(strings) << "\n";

  return 0;
}
