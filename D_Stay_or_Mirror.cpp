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
       vector<int> p(n);for(auto &i:p) cin>>i;
       int ans=0;
       for(int i=0;i<n;i++){
        int cntL=0,cntR=0;
        for(int j=0;j<i;j++){
            cntL+=(p[j]>p[i]);
        }
        for(int j=i+1;j<n;j++){
            cntR+=(p[j]>p[i]);
        }
        ans+=min(cntL,cntR);
       }
       cout<<ans<<"\n";
    }
    return 0;
}