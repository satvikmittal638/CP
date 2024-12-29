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
       ll n,x;cin>>n>>x;
       vector<ll> a(n);for(auto &i:a) cin>>i;
       sort(rall(a));
       int ans=0;
        for(int i=0;i<n;i++){
            int start=i;
            while(i<n && a[i]*(i-start+1)<x){
                i++;
            }
            if(i<n){
                ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}