#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int n,m;cin>>n>>m;
    vector<ll> a(n);for(auto &i:a) cin>>i;
    if(n>m){
        cout<<0;
    }
    else{
        ll ans=1ll;
        for(int j=0;j<n;j++){
            for(int i=0;i<j;i++){
                ans*=abs(a[i]-a[j]);
                ans%=m;
            }
        }
        cout<<ans;
    }
    return 0;
}