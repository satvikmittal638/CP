#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
    fastio;
    string s;
    getline(cin, s);  // read full line
    
    vector<ll> l,r;
    
    stringstream ss(s);
    string token;
    
    while (getline(ss, token, ',')) {   // split by comma
        ll L, R;
        sscanf(token.c_str(), "%lld-%lld", &L, &R);  // parse L-R
        l.emplace_back(L);
        r.emplace_back(R);
    }
    // for(int i=0;i<l.size();i++) cout<<l[i]<<' '<<r[i]<<'\n';
    ll ans=0ll;
    for(ll mask=10,k=0;mask<=1e10;mask*=10,k++){
        ll m=mask+1;// m=10..01 with k 0s in b/w
        for(int i=0;i<l.size();i++){
            ll L=max((l[i]+m-1)/m,mask/10), R=min(r[i]/m,mask-1);// find intersection length with all no's with (k+1) digits
            if(L<=R) ans+=m*(R*(R+1)/2 - L*(L-1)/2);
            // cout<<ans<<'\n';
        }
    }
    cout<<ans<<'\n';

}