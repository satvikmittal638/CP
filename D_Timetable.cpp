#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const int INF=1e9;
int main()
{
fastio;
    int n,m,k;cin>>n>>m>>k;
    vector<string> a(n+1);
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        a[i]=' '+a[i];//make 1-indexed
    }
    /*
    mn[i][j] denotes minm hours required to attend j lectures on
    ith day
    
    cnt[i] denotes total lecs on ith day
    */

    vector<vector<int>> mn(n+1,vector<int>(m+1,INF));
    vector<int> cnt(n+1,0);
    for(int i=1;i<=n;i++){
        mn[i][0]=0;
        
        // build prefix to count no. of 1s in a segment
        vector<int> p(m+1);
        for(int z=1;z<=m;z++){
            p[z]=p[z-1]+(a[i][z]-'0');
        }
        cnt[i]=p[m];


        // fix a window size and vary the start of it
        for(int l=1;l<=m;l++){
            for(int st=1;st<=m-l+1;st++){
                int cntLecs=p[st+l-1]-p[st-1];
                mn[i][cntLecs]=min(mn[i][cntLecs],l);
            }
        }
    }

    // for(int i=1;i<=n;i++){
    //     for(int j=0;j<=m;j++){
    //         cout<<mn[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    /*
    dp[i][j] is ans for [1,i] for a total of j lecs
    */
    vector<vector<int>> dp(n+1,vector<int>(m+1,INF));
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        // attend j lectures in total till ith day
        for(int j=0;j<=m;j++){
            // attend l lectures on the ith day
            for(int l=j;l<=cnt[i];l++){
                dp[i][j]=min(dp[i][j],dp[i-1][j-l]+mn[i][l]);
            }
        }
    }

    cout<<"dp\n";
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    int total=accumulate(all(cnt),0),ans=INF;
    for(int i=max(0, total-k);i<=total;i++){
        ans=min(ans,dp[n][i]);
    }
    // cout<<total;
    // cout<<ans;

    return 0;
}