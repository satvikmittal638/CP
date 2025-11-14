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
       map<int,int> cnt;
       for(int i=1;i<=n;i++){
        int x;cin>>x;
        cnt[x]++;
       }
       int ans=cnt[0];
       if(cnt[-1]%2!=0) ans+=2;
       cout<<ans<<'\n';
    }
    return 0;
}