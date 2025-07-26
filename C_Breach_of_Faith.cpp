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
       ll n;cin>>n;
       vector<ll>b(2*n);for(auto &i:b) cin>>i;
       sort(rall(b));
       vector<ll> a(2*n+2,0);
       ll j=0;
       a[1]=b[j];
       a[2*n]+=a[1];
       j++;
       for(ll i=3;i<=2*n+1;i+=2){
        a[i]=b[j];
        a[2*n]+=a[i];
        j++;
       }
       for(ll i=2;i<=2*n-2;i+=2){
        a[i]=b[j];
        a[2*n]-=a[i];
        j++;
       }
       for(ll i=1;i<=2*n+1;i++) cout<<a[i]<<" ";
       cout<<"\n";


    }
    return 0;
}