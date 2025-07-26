#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int N,t,T;cin>>N>>t;
    T=2*t-1;
    /*
    dp[n][t][h] denotes no. of ways to reach the end(n=N) from current state
    at (n,h) having no. of breaks=t to complete total of T=2t-1 breaks
    */
    int dp[25][25][10];
    memset(dp,0,sizeof(dp));
    /*
    Base case:we are at the end with exactly T breaks
    */
    for(int h=1;h<=4;h++){
        dp[N][T][h]=1;
    }
    for(int i=N;i>=1;i--){
        for(int t=0;t<=T;t++){
            for(int h=1;h<=4;h++){
                // last break was a cavity, so we are moving up currently
                if(t%2==0){
                    for(int H=1;H<=4;H++){
                        // move up->no change in break
                        if(H>h){
                            dp[i][t][h]+=dp[i+1][t][H];
                        }
                        // move down-> no. of breaks increases by 1
                        else if(H<h){
                            dp[i][t][h]+=dp[i+1][t+1][H];
                        }
                    }
                }
                else{
                    // last break was a hump, so we are moving down currently
                    for(int H=1;H<=4;H++){
                        // move down->no change in break
                        if(H<h){
                            dp[i][t][h]+=dp[i+1][t][H];
                        }
                        // move up-> no. of breaks increases by 1
                        else if(H>h){
                            dp[i][t][h]+=dp[i+1][t+1][H];
                        }
                    }
                }
            }
        }
    }
    
    ll ans=0ll;
    /*
    There are (h-1) ways to reach from x=1 to (2,h)
    (1,1),(1,2)..(1,h-1)
    */
    for(int h=1;h<=4;h++){
        ans+=(h-1)*dp[2][0][h];
    }
    cout<<ans;
    return 0;
}