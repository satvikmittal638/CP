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
    int n,k;cin>>n>>k;
    string s;cin>>s;
    // dp[i][j] is idx of 1st occ of char j on suffix [i,n-1]
    vector<vector<int>> dp(n+1,vector<int>(k,INT_MAX));
    for(int i=n-1;i>=0;i--){
        dp[i]=dp[i+1];
        dp[i][s[i]-'a']=i;
    }
    // precompute length of smallest string not present as a subsequence for each suffix
    // let dp2[i] be this for [i,n-1]
    vector<int> dp2(n+1,0);
    for(int i=n-1;i>=0;i--){
        int mxstart=*max_element(all(dp[i]));
        if(mxstart<n) dp2[i]=1+dp2[mxstart+1];
    }
    int q;cin>>q;
    while(q--){
        string t;cin>>t;
        int m=t.size();
        // skip over earliest occuring subsequence of s=t
        int j=-1;
        for(int i=0;i<m && j<INT_MAX;i++){
            j=dp[j+1][t[i]-'a'];
        }
        int ans=0;
        if(j<n)ans=1+dp2[j+1]; 
        cout<<ans<<'\n';
    }
    return 0;
}