#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<int> a(n);
       vector<long long> ctr(32,0ll);
       vector<bool> taken(n,0);
       for(auto &i:a) cin>>i;
       for(int pos=31;pos>=0;pos--){
        for(int i=0;i<n;i++){
            // if set bit at pos for a elt which is not taken till yet
            if(!taken[i] && a[i]&(1<<pos)){
                ctr[pos]++;
                taken[i]=1;
            }
        }
       }
       long long ans=0ll;
        for(int pos=31;pos>=0;pos--){
            ans+=ctr[pos]*(ctr[pos]-1)/2;
        }
        cout<<ans<<"\n";
       
    }
    return 0;
}