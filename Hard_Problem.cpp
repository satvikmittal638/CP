#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const int MAX=1e5+1;
int n;
string s;
vector<ll> cost;
ll dp[MAX][4];
// ans for s[0,i] if prefix of length j of 'hard' is already found as a subsequence
ll rec(int i,int j){
    // prune
    if(i<0){
        if(j==0) return 0;
        else return 1e18;// invalid state
    }
    // base

    // cache check
    if(dp[i][j]!=-1) return dp[i][j];
    // compute and save
    ll ans=1e18;
    // delete s[i]
    ans=min(ans,rec(i-1,j)+cost[i]);

    // try to keep the char
    if(j==0){
        if(s[i]!='h') ans=min(ans,rec(i-1,0));
    }
    else if(j==1){
        if(s[i]=='h') ans=min(ans,rec(i-1,0));
        if(s[i]!='a') ans=min(ans,rec(i-1,1));
    }
    else if(j==2){
        if(s[i]=='a') ans=min(ans,rec(i-1,1));
        if(s[i]!='r') ans=min(ans,rec(i-1,2));
    }
    else if(j==3){  
        if(s[i]=='r') ans=min(ans,rec(i-1,2));
        if(s[i]!='d') ans=min(ans,rec(i-1,3));
    }
    return dp[i][j]=ans;
}

int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       cin>>n>>s;cost.assign(n,0);
       for(auto &i:cost) cin>>i;
       memset(dp,-1,sizeof(dp));
       cout<<min({rec(n-1,0),rec(n-1,1),rec(n-1,2),rec(n-1,3)})<<'\n';
    }
    return 0;
}