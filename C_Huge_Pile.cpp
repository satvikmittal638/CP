#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const int INF=1e9+10;
map<int, int> memo;

// minm cost to get pile of k given n apples
int rec(int n,int k){
    // base
    if(n==k) return 0;

    // prune
    if(n < k){
       return INF;
    }

    if(memo.count(n)) return memo[n];

    int res = 1 + min(rec(n/2,k), rec((n+1)/2,k));
    return memo[n] = res;
} 
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
        memo.clear();
       int n,k;cin>>n>>k;
       int ans=rec(n,k);
       if(ans>=INF) ans=-1;
       cout<<ans<<'\n';
    }
    return 0;
}