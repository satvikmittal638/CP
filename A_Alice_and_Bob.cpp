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
       int n,a;cin>>n>>a;
       vector<int> v(n);for(auto &i:v) cin>>i;
       int cntless=0,cntGret=0;
       for(int i=0;i<n;i++){
        if(abs(v[i]-(a+1))<abs(v[i]-a)){
            cntGret++;
        }
        if(abs(v[i]-(a-1))<abs(v[i]-a)){
            cntless++;
        }
       }
       int ans=0;
       if(cntless>cntGret) ans=a-1;
       else ans=a+1;
       cout<<ans<<'\n';
    }
    return 0;
}