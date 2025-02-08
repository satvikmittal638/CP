#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    ll n;cin>>n;
    vector<ll> a(n);
    for(auto &i:a) cin>>i;
    bool ok=1;
    for(ll i=0;i<n-2;i++){
        if(a[i+1]*a[i+1]!=a[i]*a[i+2]){
            ok=0;break;
        }
    }
    cout<<(ok?"Yes":"No");
    return 0;
}