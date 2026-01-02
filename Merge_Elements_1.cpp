#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const ll INF=1e18;
int n;
vector<int> a,p;

int dp[502][502];
// ans for a[l,r]
// 1 indexed
int rec(int l,int r){
    // prune
    if(l<1 || r<1 || l>=r) return 0;
    // base
    // cache check
    if(dp[l][r]!=-1) return dp[l][r];
    // compute and save
    int ans=INT_MAX;

    for(int x=l;x<r;x++){
        ans=min(ans,rec(l,x)+rec(x+1,r)+((p[x]-p[l-1])%100) * ((p[r]-p[x])%100));
    }
    return dp[l][r]=ans;
}

int main()
{
fastio;
    cin>>n;a.assign(n+1,0);p.assign(n+1,0);
    for(int i=1;i<=n;i++) cin>>a[i];
    partial_sum(all(a),p.begin());
    memset(dp,-1,sizeof(dp));
    cout<<rec(1,n);
    return 0;
}