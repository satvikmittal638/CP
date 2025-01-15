#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

int main() {
    fastio;
    string s;
    cin >> s;
    int n = s.length();
    vector<ll> dp1(26,0ll);
    vector<vector<ll>> dp2(26,vector<ll>(26,0ll));
    for(int i=0;i<n;i++){
        int c=s[i]-'a';
        for(int j=0;j<26;j++){
            dp2[j][c]+=dp1[j];
        }
        dp1[c]++;
    }
    ll ans=*max_element(all(dp1));
    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
            ans=max(ans,dp2[i][j]);
        }
    }
    cout<<ans<<"\n";


    return 0;
}