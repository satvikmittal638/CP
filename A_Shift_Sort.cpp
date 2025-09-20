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
       string s;cin>>s;
       int cnt0=count(all(s),'0');
       int ans=0;
       for(int i=cnt0;i<n;i++){
        ans+=s[i]=='0';
       }
       cout<<ans<<'\n';
    }
    return 0;
}