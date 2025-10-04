#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int R,G,B;cin>>R>>G>>B;
    vector<ll> r(R+1),g(G+1),b(B+1);
    for(int i=1;i<=R;i++) cin>>r[i];
    for(int i=1;i<=G;i++) cin>>g[i];
    for(int i=1;i<=B;i++) cin>>b[i];
    sort(r.begin()+1, r.end(), greater<ll>());
    sort(g.begin()+1, g.end(), greater<ll>());
    sort(b.begin()+1, b.end(), greater<ll>());
    vector<vector<vector<ll>>> dp(R+1,vector<vector<ll>>(G+1,vector<ll>(B+1,0ll)));
    for(int i=0;i<=R;i++)
    for(int j=0;j<=G;j++)
        for(int k=0;k<=B;k++) {
            // atleast 2 different colors are taken
            if(i && j) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k] + r[i]*g[j]);
            if(j && k) dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k-1] + g[j]*b[k]);
            if(i && k) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-1] + r[i]*b[k]);
        }
                
    ll ans=0ll;
    for(int i=0;i<=R;i++) for(int j=0;j<=G;j++) for(int k=0;k<=B;k++) ans=max(ans,dp[i][j][k]);
    cout<<ans;
    return 0;
}