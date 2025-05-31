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
       // try all subarrays
       int ans=INT_MAX;
       for(int l=0;l<n;l++){
        for(int r=l;r<n;r++){
            if((a[l]+a[r])%2==0){
                ans=min(ans,n-(r-l+1));
            }
        }
       }
       cout<<ans<<"\n";
       
    }
    return 0;
}