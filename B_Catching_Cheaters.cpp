#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const int MAX=5005;

ll solve(string a,string b){
    int n=a.size(),m=b.size();
    
    vector<vector<int>> dp(26,vector<int>(m+1,MAX)); 
    for (int i = m-1; i >= 0; --i) {
        for (int c = 0; c < 26; ++c)
            dp[c][i] = dp[c][i+1];
        dp[b[i]-'a'][i] = i;
    }
    
    ll ans=0ll;
    for(int l=0;l<n;l++){
        ll cur=0ll;
        int lastPosB=-1;
        for(int r=l;r<n;r++){
            int searchPos = (lastPosB == -1) ? 0 : lastPosB + 1;
            int nxtPosB=dp[a[r]-'a'][searchPos];
            
            if(nxtPosB<m){
                if(lastPosB == -1) {
                    cur = 2; 
                } else {
                    cur += 3 - (nxtPosB - lastPosB);
                }
                ans=max(ans,cur);
                lastPosB=nxtPosB;
            }
            else{
                break;
            }
        }
    }
    return ans;
}

int main()
{
fastio;
    int n,m;cin>>n>>m;
    string a,b;cin>>a>>b;
    cout<<max(solve(a,b), solve(b,a));
    return 0;
}