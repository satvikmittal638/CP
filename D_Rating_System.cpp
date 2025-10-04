#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<ll> a(n);for(auto &i:a) cin>>i;
       ll mn=LLONG_MAX,l=-1,mxPref=0,curPref=0ll,lans=-1;
       // find minm subarray sum
       for(int i=0;i<n;i++){
        curPref+=a[i];
        ll cur=curPref-mxPref;
        if(mn>=cur){
            lans=l;
            mn=cur;
        }
        if(curPref>=mxPref){
            mxPref=curPref;
            l=i;
        }
       }
       cout<<accumulate(a.begin(),a.begin()+lans+1,0ll)<<'\n';
    }
    return 0;
}