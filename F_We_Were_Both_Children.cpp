#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       map<int,int> f;
       vector<ll> ctr(n+1,0);
       for(int i=0;i<n;i++){
        int a;cin>>a;
        f[a]++;
        //
       }
       for(auto p:f){
        int a=p.first;
        for(int j=a;j<=n;j+=a){
            ctr[j]+=p.second;
        }
       }
       ll ans=*max_element(ctr.begin(),ctr.end());
       cout<<ans<<"\n";
    }
    return 0;
}