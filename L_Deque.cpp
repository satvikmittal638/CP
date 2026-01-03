#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const ll INF=1e18;
int n;
vector<ll> a;
ll dp[3001][3001];
bool done[3001][3001];
// optimal score of a[l,r] with optimizing(maximizing) my score-other's score
ll rec(int l,int r){
    //prune
    if(l<0 || r<0 || l>=n || r>=n || l>r) return 0; // empty

    // cache check
    if(done[l][r]) return dp[l][r];

    // compute and save
    // make 2 moves so that chance throws back to Taro
    // jiro is not forced to make a move
    // do a multiplcation with -1 since next chance is of opponent, so he outputs his score-my score
    // so -1 flips back to myscore-his score
    // and I am maximizing the score(essentially both players are using the same strategy)
    ll ans=max(a[l]-rec(l+1,r),a[r]-rec(l,r-1));
    done[l][r]=1;
    return dp[l][r]=ans;
}

int main()
{
fastio;
    cin>>n;
    a.assign(n,0);for(auto &i:a) cin>>i;
    for(int i=0;i<=3000;i++) for(int j=0;j<=3000;j++) dp[i][j]=-INF;
    memset(done,0,sizeof(done));
    cout<<rec(0,n-1);
    return 0;
}