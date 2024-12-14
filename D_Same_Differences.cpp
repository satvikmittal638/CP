#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       map<int,long long> cnt;
       for(int i=1;i<=n;i++){
        long long a;cin>>a;
        cnt[a-i]++;
       }
       long long ans=0ll;
       for(auto &p:cnt){
        long long k=p.second;
        ans+=k*(k-1)/2;
       }
       cout<<ans<<"\n";
    }
    return 0;
}