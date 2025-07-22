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
    if(n==1) {
        cout<<1;
        return 0;
    }
    else if(n==2){
        cout<<2;
        return 0;
    }
    else if(n==3){
        cout<<6;
        return 0;
    }
    ll ans;
    if(n%2!=0) ans=n*(n-1)*(n-2);
    else{
        if(n%3==0) ans=(n-1)*(n-2)*(n-3);
        else ans=n*(n-1)*(n-3);
    }
    cout<<ans;
    return 0;
}