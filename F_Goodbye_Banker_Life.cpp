#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
const int MAX=1e6;
// precompute highest power of 2 in all numbers till MAX
vector<ll> pow2(MAX+1,0ll);
for(int i=1;i<=MAX;i++){
    ll n=i;
    // Legendre's formula
    // O(logn)
    while(n){
        n/=2;
        pow2[i]+=n;
    }
}
    int tt;cin>>tt;
    while(tt--){
       int n,k;cin>>n>>k;
       n--;// make 0-indexed
       for(int r=0;r<=n;r++){
        if(pow2[n]==(pow2[r]+pow2[n-r])){
            cout<<k<<" ";
        }
        else{
            cout<<"0 ";
        }
       }
       cout<<"\n";

    }
    return 0;
}