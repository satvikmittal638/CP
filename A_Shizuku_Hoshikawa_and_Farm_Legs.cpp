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
       int ans=0;
       for(int a=0;a<=n;a++){
        if(n>=2*a && (n-2*a)%4==0) ans++;
       }
       cout<<ans<<'\n';
    }
    return 0;
}