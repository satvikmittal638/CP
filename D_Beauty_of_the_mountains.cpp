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
       int n,m,k;cin>>n>>m>>k;
       vector<vector<ll>> a(n+1,vector<ll>(m+1,0ll));
       for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
       }
       vector<string> s(n+1);
       for(int i=1;i<=n;i++){
        cin>>s[i];
        s[i]=' '+s[i];
       }
       ll D=0ll; // initial diff of heights (cnt0-cnt1)
       vector<vector<ll>> pref(n+1,vector<ll>(m+1,0ll));
       for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            D+=(s[i][j]=='0')*a[i][j];
            D-=(s[i][j]=='1')*a[i][j];
            pref[i][j]=(pref[i][j-1]+pref[i-1][j]-pref[i-1][j-1])+(s[i][j]=='0')-(s[i][j]=='1');
        }
       }

       ll h1=0ll;
       for(int i=k;i<=n;i++){
        for(int j=k;j<=m;j++){
            ll cur=pref[i][j]-pref[i-k][j]-pref[i][j-k]+pref[i-k][j-k];
            h1=gcd(h1,cur);
        }
       }
       if(h1==0){
        cout<<((D==0)?"YES":"NO")<<"\n";
        continue;
       }
       cout<<((D%h1==0)?"YES":"NO")<<"\n";
    }
    return 0;
}