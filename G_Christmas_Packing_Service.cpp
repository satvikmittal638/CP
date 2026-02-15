#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()


int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<int> a(n);for(auto &i:a) cin>>i;
       // coordinate compress
       vector<int> tmp(a);
       sort(all(tmp));
       a.erase(unique(all(a)), a.end());
       map<int,int> inv;
       for(int i=0;i<tmp.size();i++){
        inv[tmp[i]]=i;
       }
       for(int i=0;i<n;i++){
        a[i]=inv[a[i]];
       }
       // now all elts b/w 0 and n
       // let dp[i] be the rightmost index of a elt x
       vector<int> dp(n+1,-1);
       for(int i=n-1;i>=0;i--){
        if(dp[a[i]]==-1) dp[a[i]]=i;
       }
       
       
    }
    return 0;
}