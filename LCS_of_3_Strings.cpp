#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const int MAX=101;
int dp[MAX][MAX][MAX];
string s1,s2,s3;

int rec(int i,int j,int k){
    if(i>=s1.length() || j>=s2.length() || k>=s3.length())
        return 0;

    int &res = dp[i][j][k];
    if(res != -1) return res;

    if(s1[i]==s2[j] && s2[j]==s3[k]) {
        // ONLY ONE call
        return res = 1 + rec(i+1, j+1, k+1);
    }

    // ONLY when mismatch
    return res = max({
        rec(i+1, j, k),
        rec(i, j+1, k),
        rec(i, j, k+1)
    });
}

int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       cin>>s1>>s2>>s3;
       memset(dp,-1,sizeof(dp));
        cout<<rec(0,0,0)<<'\n';
    }
    return 0;
}