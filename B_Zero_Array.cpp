#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int n;cin>>n;
    ll s=0ll,mx=LLONG_MIN;
    for(int i=0;i<n;i++){
        ll x;cin>>x;
        mx=max(mx,x);
        s+=x;
    }
    if(s%2==0 && (s-mx)>=mx){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }

    return 0;
}