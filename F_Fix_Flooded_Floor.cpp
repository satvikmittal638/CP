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

int main()
{
fastio;
    ll tt;cin>>tt;
    while(tt--){
       ll n;cin>>n;
       vector<string> s(2);cin>>s[0]>>s[1];
       vector<vector<ll>> dp(n,vector<ll>(4,0));
       auto config=[&](ll i){
        if(s[0][i]=='.' && s[1][i]=='.') return 0;// EE
        else if(s[0][i]=='.' && s[1][i]=='#') return 1;// EF
        else if(s[0][i]=='#' && s[1][i]=='.') return 2;// FE
        if(s[0][i]=='#' && s[1][i]=='#') return 3; // FF
       };
       // base case for 1st col
       dp[0][config(0)]=1;
       if(config(0)==0) dp[0][3]+=1; // EE can be made FF

       for(ll i=1;i<n;i++){
        int c=config(i);
        if(c==0) {
            // prvs is FF
            // place or leave
            dp[i][0]+=dp[i-1][3];
            dp[i][3]+=dp[i-1][3];

            // prvs is EE
            // put 2 horizontal
            dp[i][3]+=dp[i-1][0];

            // prvs is EF
            // horizontal on top
            dp[i][2]+=dp[i-1][1];

            // prvs is FE
            // horizontal at bottom
            dp[i][1]+=dp[i-1][2];
        }
        else if(c==1){// FE
            // prvs is FF
            // keep current unchanged
            dp[i][1]+=dp[i-1][3];

            //prvs is EF
            // horizontal on top
            dp[i][3]+=dp[i-1][1];
        }
        else if(c==2){//EF
            // prvs is FF
            // unchanged
            dp[i][2]+=dp[i-1][3];

            // prvs is FE
            // horizontal at bottom
            dp[i][3]+=dp[i-1][2];
            
        }
        else{// FF
            // unchanged
            dp[i][3]+=dp[i-1][3];
        }


        // cap at 2 to prevent explode
        for(int j=0;j<4;j++) dp[i][j]=min(dp[i][j],2ll);

       }
       ll ways=dp[n-1][3];
       if(ways==0){
        cout<<"None";
       }
       else if(ways==1){
        cout<<"Unique";
       }
       else{
        cout<<"Multiple";
       }
       cout<<'\n';
    }
    return 0;
}