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
       sort(all(a));
       int ans=INT_MAX;
       for(int i=0;i<n-2;i++){
        int j=lower_bound(all(a),a[i]+a[i+1])-a.begin()-1;
        if(j>=0){
            ans=min(ans,n-(j-i+1));
        }
       }
       cout<<ans<<"\n";
    }
    return 0;
}