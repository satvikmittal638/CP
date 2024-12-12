#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<long long> a(n);for(auto &i:a) cin>>i;
       sort(a.begin(),a.end());
       long long ans=max({
        a[n-1]*a[n-2]*a[n-3]*a[n-4]*a[n-5],
        a[n-1]*a[n-2]*a[n-3]*a[0]*a[1],
        a[n-1]*a[0]*a[1]*a[2]*a[3]
       });
       cout<<ans<<"\n";
    }
    return 0;
}