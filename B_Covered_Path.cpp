#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int v1,v2,t,d;cin>>v1>>v2>>t>>d;
    ll ans=0ll;
    for(int i=0;i<t;i++){
        ans+=min(v1+d*i,v2+d*(t-1-i));
    }
    cout<<ans;

    return 0;
}