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
       map<ll,ll> cnt;
       for(int i=0;i<n;i++){
        ll a;cin>>a;
        cnt[a]++;
       }
       int q;cin>>q;
       while(q--){
        ll x,y;cin>>x>>y;
        ll D=(x*x-4*y),sq=sqrt(D);
        ll ans=0ll;
        if(sq*sq==D){
            // cout<<"hi";
            D=sq;
            ll a=x+D, b=x-D;
            if(a%2==0){
                a/=2;b/=2;
                if(a!=b){
                    ans=cnt[a]*cnt[b];
                }
                else{
                    ans=cnt[a]*(cnt[a]-1)/2;
                }
            }
        }
        cout<<ans<<" ";
       }
       cout<<"\n";
    }
    return 0;
}