#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    ll tt;cin>>tt;
    while(tt--){
       ll q;cin>>q;
       ll h1=1,h2=LLONG_MAX;
       while(q--){
        ll t;cin>>t;
        if(t==1){
            ll a,b,n,lo,hi;cin>>a>>b>>n;
            lo=(n-2)*(a-b)+a+1;
            hi=(n-1)*(a-b)+a;
            // edge case
            if(n==1){
                lo=1;
                hi=a;
            }

            // there is llersection, so we llersect and narrow down range of h
            if(max(lo,h1)<=min(hi,h2)){
                h1=max(h1,lo);
                h2=min(h2,hi);
                cout<<"1 ";
            }
            // no llersection, invalid
            else{
                cout<<"0 ";
            }
        }
        else{
            ll a,b;cin>>a>>b;
            ll n1=max(((h1-a)+(a-b)-1)/(a-b) + 1,1ll);// clip at 1 for h1<=a
            ll n2=max(((h2-a)+(a-b)-1)/(a-b) + 1,1ll);// clip at 1 for h1<=a
            if(n1!=n2){
                cout<<"-1 ";
            }
            else{
                cout<<n1<<' ';
            }
        }
       }
       cout<<'\n';
    }
    return 0;
}