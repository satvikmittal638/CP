#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
string s;
int dp[1001][1001];
// rec(l,r) is LPS of s[l,r]
// 0 indexed
int rec(int l, int r){
    // prune
    if(l<0 || r<0 || l>r) return 0;

    // base case
    // if(l==r) return 1;
    // cache check
    if(dp[l][r]!=-1) return dp[l][r];
    // compute and save
    int ans=0;
    if(s[l]==s[r]){
        ans=rec(l+1,r-1)+1+(l<r);// length increases by 2 iff l!=r
    }
    else{
        ans=max(rec(l+1,r),rec(l,r-1));
    }
    return dp[l][r]=ans;
}
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       cin>>s;
       memset(dp,-1,sizeof(dp));
       cout<<s.length()-rec(0,s.size()-1)<<'\n';
    }
    return 0;
}