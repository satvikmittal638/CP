#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const int MAX=1e3+1;
bool dp[MAX][MAX];
int main()
{
fastio;
    int n,m;cin>>n>>m;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]%=m;
    }
    if(n>m){
        cout<<"YES\n";
        return 0;
    }
    memset(dp, 0, sizeof(dp));

    // base case(use 1 elt subsets instead of empty of subsets for each prefix)
    // this is because at end we may be considering empty subset as our ans
    for(int i=1;i<=n;i++) dp[i][a[i]]=1;

    // dp[i][j] -> is there a subset from [1,i] s.t sum % m == j ?
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            dp[i][j] |= dp[i-1][j] |
                    dp[i-1][(j - a[i] + m) % m];
        }
    }
    // check if we have a non-empty subseq divisible by m
    cout << (dp[n][0] ? "YES" : "NO");
    return 0;
}