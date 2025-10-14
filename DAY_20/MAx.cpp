#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int mx = -1;
   
    for (int i = 0; i < n; i++) 
    {
        int y;
        cin >> y;
        if (y > mx) // update
            mx = y;
    }

    cout << mx << "\n";

    return 0;
}
