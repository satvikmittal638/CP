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
       vector<int> a(n+1),pref(n+1,0);
       for(int i=1;i<=n;i++){
        cin>>a[i];
        pref[i]=pref[i-1]+a[i];
       }
       int ans=0;
       for(int i=1;i<=n-k+1;i++){
        if(pref[i+k-1]==pref[i-1]){
            ans++;
            i+=k;
        }
       }
       cout<<ans<<"\n";
    }
    return 0;
}