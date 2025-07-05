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
        int ans=-2;
       for(int i=0;i<n-1;i++){
        if(abs(a[i+1]-a[i])<=1){
            ans=0;
            break;
        }
       }
       if(ans==-2){
        if(is_sorted(all(a)) || is_sorted(rall(a))) ans=-1;
       }
       if(ans==-2){
        ans=1;
       }
       cout<<ans<<"\n";
    }
    return 0;
}