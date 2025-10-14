#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; // find_by_order, order_of_key

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        ordered_set s;
        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            s.insert({i,temp});
        }
        
        for(int i=0;i<n;i++)
        {
            int pos;
            cin>>pos;
            auto itr=s.find_by_order(pos-1);
            cout<<(*itr).second<<" ";
            s.erase(itr);
        }
        cout<<endl;
    }
}
