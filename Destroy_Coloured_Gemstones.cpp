#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
vector<int> a;
int n;
const int INF=1e9;
int dp[101][101];

// minm cost to delete a[l,r](0-indexed)
int rec(int l,int r){
    // prune
    if(l<0 || r<0 || l>r) return 0; // empty subarrays
    // base
    
    // cache check
    if(dp[l][r]!=-1) return dp[l][r];
    // compute and save
    int ans=1+rec(l+1,r);// delete single char
    if(l<n && a[l]==a[l+1]) ans=min(ans,1+rec(l+2,r)); // delete 2 consec char(special case)

    for(int i=l+2;i<=r;i++){
        // match a[l] with some a[i], and do their deletion when doing last operation on subarray [l+1,i-1]
        // also then delete for remaining [i+1,r]
        if(a[l]==a[i]){
            ans=min(ans,rec(l+1,i-1)+rec(i+1,r));
        }
    }
    return dp[l][r]=ans;
}

int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
        cin>>n;a.assign(n,0);
        for(auto &i:a) cin>>i;
        memset(dp,-1,sizeof(dp));
        cout<<rec(0,n-1)<<'\n';
    }
    return 0;
}