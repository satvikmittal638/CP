#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    // precompute divisors of all numbers till 1e5
    const int MAX=1e5;
    vector<vector<int>> divs(MAX+1,vector<int>());
    for(int i=1;i<=MAX;i++){
        for(int j=i;j<=MAX;j+=i){
            divs[j].push_back(i);
        }
    }
    int tt;cin>>tt;
    while(tt--){
       int n,m;cin>>n>>m;
       vector<int> a(n);for(auto &i:a) cin>>i;
       sort(all(a));
       int l=0;
       vector<int> f(m+1,0);
       int cnt=0,ans=INT_MAX;
       for(int r=0;r<n;r++){
           // add a[r] to window
           for(auto d:divs[a[r]]){
               if(d<=m) {
                   cnt+=f[d]==0; // increment the count if a new factor was found
                   f[d]++;
               }
           }
        // remove a[l] from window until we reach our target count
        while(l<=r && cnt==m){
            ans=min(ans,a[r]-a[l]);
            for(auto d:divs[a[l]]){
                if(d<=m){
                    cnt-=f[d]==1;// decrement the count if a factor is lost
                    f[d]--;
                }
            }
            l++;
        }
       }
       if(ans>=INT_MAX) ans=-1;
       cout<<ans<<"\n";
    }
    return 0;
}