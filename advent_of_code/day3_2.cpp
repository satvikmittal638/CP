#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    ll ans=0ll;
    string s;
    while (cin >> s)
    {
        int n=s.size();
        vector<ll> suf_mx(n+1,0ll);
        // precompute the largest k-digit no. to the right of a digit(the no. may start at the position of that digit as well)
        // then do it multiple times until we start forming k digit no's
        ll mask=1ll;
        for(int k=1;k<=12;k++){
            vector<ll> suf_mx2(n+1,0ll);
            for(int i=n-k;i>=0;i--){
                suf_mx2[i]=max((s[i]-'0')*mask+suf_mx[i+1],suf_mx2[i+1]);
            }
            mask*=10;//increase no. of digits for nxt iteration
            suf_mx=suf_mx2;
        }
        ans+=suf_mx[0];
    }
    cout<<ans;
    return 0;
}