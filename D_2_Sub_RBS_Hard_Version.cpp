#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

#ifndef ONLINE_JUDGE
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
#else
#define error(args...)
#endif
const int MAX=105;
const int MOD=998244353;
// dp[i][l][k][b] is no. of bracket seqn after processing s[1,i]
// s.t. their length=l, balance sum=b, with k length prefix of ')((' matched
int dp[MAX][MAX][4][MAX];

int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       string s;cin>>s;
       s=' '+s;// 1-indexed
       memset(dp,0,sizeof(dp));
       dp[0][0][0][0]=1; // empty
       for(int i=1;i<=n;i++){
        for(int l=0;l<=i-1;l++){
            for(int b=0;b<=i-1;b++){
                for(int k=0;k<4;k++){
                    // skip s[i] completely
                    dp[i][l][k][b]+=dp[i-1][l][k][b];
                    dp[i][l][k][b]%=MOD;

                    // choose s[i]
                    // then have following different cases
                    if(s[i]=='('){
                        if(k==1 || k==2){
                            dp[i][l+1][k+1][b+1]+=dp[i-1][l][k][b];
                            dp[i][l+1][k+1][b+1]%=MOD;
                        }
                        else{
                            dp[i][l+1][k][b+1]+=dp[i-1][l][k][b];
                            dp[i][l+1][k][b+1]%=MOD;
                        }
                    }
                    else{
                        if(b<1) continue;
                        if(k==0){
                            dp[i][l+1][k+1][b-1]+=dp[i-1][l][k][b];
                            dp[i][l+1][k+1][b-1]%=MOD;
                        }
                        else{
                            dp[i][l+1][k][b-1]+=dp[i-1][l][k][b];
                            dp[i][l+1][k][b-1]%=MOD;
                        }
                    }
                }
            }
        }
       }
       ll ans=0ll;
       for(int l=2;l<=n;l++){
        ans+=1ll*dp[n][l][3][0]*(l-2);
        ans%=MOD;
       } 
       cout<<ans<<'\n';
    }
    return 0;
}