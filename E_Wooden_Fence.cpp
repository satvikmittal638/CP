#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
    const int MOD=1e9+7;
fastio;
    int n,l;cin>>n>>l;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++)cin>>a[i]>>b[i];
    /*
    dp[i][j][k] is ans for [1,i] with last board of type j having an orientation k
    k=0-> length=a[j],width=b[j]
    k=1-> length=b[j],width=a[j]
    
    */
    ll dp[l+1][n][2];
    memset(dp,0ll,sizeof(dp));

    // Base cases
    for (int j = 0; j < n; ++j) {
        int len0 = a[j];
        if (len0 <= l) {
            dp[len0][j][0] = (dp[len0][j][0] + 1) % MOD;
        }
        if (a[j] != b[j]) { // only rotate non-square boards
            int len1 = b[j];
            if (len1 <= l) {
                dp[len1][j][1] = (dp[len1][j][1] + 1) % MOD;
            }
        }
    }

    for(int i=1;i<=l;i++){
        for(int j=0;j<n;j++){
            for(int jp=0;jp<n;jp++){
                if(jp==j) continue;

                if(i>=a[j]){
                    // current orientation is 0-> b[j] is width
                    if(a[jp]==b[j]) dp[i][j][0]+=dp[i-a[j]][jp][0];
                    if(b[jp]==b[j]) dp[i][j][0]+=dp[i-a[j]][jp][1];
                }
                

                if(a[j]!=b[j] && i>=b[j]){
                    // current orientation is 1->a[j] is width
                    if(a[jp]==a[j]) dp[i][j][1]+=dp[i-b[j]][jp][0];
                    if(b[jp]==a[j]) dp[i][j][1]+=dp[i-b[j]][jp][1];
                }
                dp[i][j][0]%=MOD;
                dp[i][j][1]%=MOD;
            }
        }
    }
    ll ans=0ll;
    for(int j=0;j<n;j++){
        ans+=dp[l][j][0]+dp[l][j][1];
        ans%=MOD;
    }
    cout<<ans;
    return 0;
}