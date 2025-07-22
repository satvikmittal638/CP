#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int n;cin>>n;
    vector<ll> a(n),b(n);
    for(auto &i:a) cin>>i;
    for(auto &i:b) cin>>i;
    map<pair<ll,ll>,ll> cntd;
    ll ans=0ll;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            if(b[i]==0) ans++;
            continue;
        }
        ll num=-b[i], den=a[i],h=gcd(abs(num),abs(den));
        num/=h;den/=h;//reduce to coprimes
        if(num==0) den=1;
        // transfer the -1 to numerator from denominator
        if(den<0) {num*=-1;den*=-1;}
        // cout<<num<<"/"<<den<<" ";
        cntd[{num,den}]++;
    }
    ll cur=0ll;
    for(auto &[frac,cnt]:cntd){
        // cout<<frac.first<<"/"<<frac.second<<" ";
        cur=max(cur,cnt);
    }
    ans+=cur;
    cout<<ans;
    return 0;
}