#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,k; cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int head=-1,tail=0;
    int cntZero=0,ans=0;
    
    while(tail<n){
        while(head+1<n &&(v[head+1]==1 || cntZero<k)){
            head++;
            if(v[head]==0) cntZero++;
        }
        ans = max(ans,head-tail+1);
       if(tail > head){
          tail++;
          head = tail-1;
       }else{
          if(v[tail]==0) cntZero--;
          tail++;
       }
    }
  cout<<ans<<endl;
}    
