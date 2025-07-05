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
       int n,s;cin>>n>>s;
       vector<int> x(n);for(auto &i:x) cin>>i;
       int ans;
       if(s<=x[0]) ans=x[n-1]-s;
       else if(s>=x[n-1]) ans=s-x[0];
       else if(x[0]<=s && s<=x[n-1]) ans=x[n-1]-x[0]+ min(x[n-1]-s,s-x[0]);
       cout<<ans<<"\n";
    }
    return 0;
}