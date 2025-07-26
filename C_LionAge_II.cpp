#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    const ll INF=-1e18;
    string s;
    ll k,n;cin>>s>>k>>n;
    ll l=s.size();
    s=' '+s;// make 1 indexed
    vector<vector<ll>> c(26,vector<ll>(26,0));
    while(n--){
        char x,y;
        ll bonus;
        cin>>x>>y>>bonus;
        c[x-'a'][y-'a']=bonus;
    }
    /*
    dp[i][j][ch_y] is ans for [1,i] with exactly j letters
    modified with s[i]:=ch_y
    */
    ll dp[105][105][30];
    // memset only works for 0 and -1
    for (ll i = 0; i < 105; i++)
        for (ll j = 0; j < 105; j++)
            for (ll ch = 0; ch < 30; ch++)
                dp[i][j][ch] = INF;

    // base-case:1 letter only
    for (ll ch = 0; ch < 26; ++ch) {
        if (ch == s[1]-'a') {
                dp[1][0][ch] = 0;
            
        } else {
                if(k>=1) dp[1][1][ch] = 0;
        }
    }
    for(ll i=2;i<=l;i++){
        for(ll j=0;j<=k;j++){
            for(ll ch_y=0;ch_y<=25;ch_y++){
                // no need to change s[i]
                if((s[i]-'a')==ch_y){
                    // check all possibilities for the prvs char
                    for(ll ch_x=0;ch_x<=25;ch_x++){
                        if (dp[i - 1][j][ch_x] ==INF) continue; // Skip invalid states
                        dp[i][j][ch_y]=max(dp[i][j][ch_y],dp[i-1][j][ch_x]+c[ch_x][ch_y]);
                    }
                }
                // will have to change s[i]
                else{
                    // if u aren't allowed to change anything
                    if(j==0) continue;
                    // check all possibilities for the prvs char
                    for(ll ch_x=0;ch_x<=25;ch_x++){
                        if (dp[i - 1][j-1][ch_x]==INF) continue; // Skip invalid states
                        dp[i][j][ch_y]=max(dp[i][j][ch_y],dp[i-1][j-1][ch_x]+c[ch_x][ch_y]);
                    }
                }
            }
        }
    }
    ll ans=INF;
    // u can make any no. of changes from 0 to k
    for(ll j=0;j<=k;j++){
        // the word may end with any letter
        for(ll ch_y=0;ch_y<=25;ch_y++){
            ans=max(ans,dp[l][j][ch_y]);
        }
    }
    cout<<ans;
    return 0;
}