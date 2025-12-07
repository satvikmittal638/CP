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
    ll ans=0ll;
    for(int i=0;i<l.size();i++){
        // p is length of repeating segment
        // k is no. of times this segment is rpted
        for(ll p=1;p<=9;p++){
            for(ll k=2;k*p<=9;k++){
                ll m=(pow(10,(p+1)*k)-1)/(pow(10,p+1)-1),mask=pow(10,p);
                
                ll L=max((l[i]+m-1)/m,mask/10), R=min(r[i]/m,mask-1);// find intersection length with all no's with p digits
                if(L<=R) ans+=m*(R*(R+1)/2 - L*(L-1)/2);
            }
        }
    }
    cout<<ans<<'\n';

}