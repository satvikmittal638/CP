#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

ll score(ll l,ll r,ll k){
    ll len=r-l+1;
    if(len<k) return 0ll;
    int m=(l+r)/2;
    if(len%2==0){
        return score(l,m,k)+score(m+1,r,k);
    }
    else{
        return score(l,m-1,k)+score(m+1,r,k) + m;
    }
}

int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       ll n,k;cin>>n>>k;
        cout<<score(1,n,k)<<"\n";
    }
    return 0;
}