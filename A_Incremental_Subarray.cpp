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
       int n,m;cin>>n>>m;
       vector<int> a(m);for(auto &i:a) cin>>i;
       int ans=1;
       bool isStrictInc=1;
       for(int i=1;i<m;i++){
        if(a[i]<=a[i-1]) isStrictInc=0;
       }
       if(isStrictInc){
        int k=a[m-1];
        ans=n-k+1;
       }
       cout<<ans<<'\n';
    }
    return 0;
}