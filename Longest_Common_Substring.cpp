#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const int MAX=1e3+1;
string s1,s2;
int dp[MAX][MAX];
// substring ending at i on s1, at j on s2 after processing s1[0,i] s2[0,j]
int rec(int i,int j){
    // prune/base case
    if(i>=s1.length() || j>=s2.length()) return 0;

    //cache check
    if(dp[i][j]!=-1) return dp[i][j];
    // compute and save
    int ans=0;
    if(s1[i]==s2[j]) ans=1+rec(i+1,j+1);

    return dp[i][j]=ans;


}

int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
        cin>>s1>>s2;
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(int i=0;i<s1.length();i++){
            for(int j=0;j<s2.length();j++){
                ans=max(ans,rec(i,j));
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}