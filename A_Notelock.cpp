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
       string s;cin>>s;
       vector<int> p(n+1,0);
       s=' '+s;
       for(int i=1;i<=n;i++){
        p[i]=p[i-1]+(s[i]-'0');
       }
       int ans=0;
       for(int i=1;i<=n;i++){
        // prvs k-1 have atleast a 1, so need to protect
        if(s[i]=='1' && (p[i-1]-p[max(1,i-k+1)-1])==0){
            ans++;
        }
       }
       cout<<ans<<'\n';
    }
    return 0;
}