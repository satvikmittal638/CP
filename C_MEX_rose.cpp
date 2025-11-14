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
       int n,k;cin>>n>>k;
       vector<int> cnt(n+1,0);
       vector<int> a(n);
       for(auto &i:a) {
        cin>>i;
        cnt[i]++;
       }
       int ans=0;
       for(int i=0;i<k;i++){
        if(cnt[i]==0) ans++;
       }
       // first try to use operations on k
       // if no. of operations used till now can't remove all ks, do more operations
       if(ans<cnt[k]){
        ans+=cnt[k]-ans;
       }
       cout<<ans<<'\n';
      
       
       
    }
    return 0;
}