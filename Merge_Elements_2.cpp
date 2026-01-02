#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const ll INF=1e18;
int n,x,y,z;
vector<int> a;

int dp[502][502][52];
bool vis[502][502];
// ans for a[l,r] with final merge value of xx
// 1 indexed
int rec(int l,int r,int xx){
    // prune
    if(l<1 || r<1 || l>r) return 0;
    // base
    if(l==r){
        if(a[l]==xx) return 0;
        else return 1e9;
    }
    // cache check
    if(vis[l][r]) return dp[l][r][xx];
    // compute and save
    for(int i=0;i<50;i++) dp[l][r][i]=1e9;
    for(int mid=l;mid<r;mid++){
        for(int fs=0;fs<50;fs++){
            for(int ls=0;ls<50;ls++){
                dp[l][r][(fs*x+ls*y+z)%50]=min(dp[l][r][(fs*x+ls*y+z)%50],rec(l,mid,fs)+rec(mid+1,r,ls)+fs*ls);
            }
        }
    }
    vis[l][r]=1;
    return dp[l][r][xx];
}

int main()
{
fastio;
    cin>>n>>x>>y>>z;
    a.assign(n+1,0);
    for(int i=1;i<=n;i++) cin>>a[i];
    memset(dp,-1,sizeof(dp));
    int ans=1e9;
    for(int xx=0;xx<50;xx++) ans=min(ans,rec(1,n,xx));
    cout<<ans;
    return 0;
}