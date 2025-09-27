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
       vector<int> cnt(n+1,0);
       for(int i=0;i<n;i++){
        int x;cin>>x;
        cnt[x]++;
       }
       int ans=0;
       for(int k=1;k<=n;k++){
        int cur=0;
           for(int i=1;i<=n;i++){
                if(cnt[i]>=k) cur+=k;
           }
           ans=max(ans,cur);
       }
       cout<<ans<<'\n';
    }
    return 0;
}