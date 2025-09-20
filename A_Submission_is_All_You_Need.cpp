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
       vector<int> cnt(51,0);
       ll ans=0ll;
       for(int i=0;i<n;i++){
        int x;cin>>x;
        ans+=x;
        cnt[x]++;
       }
       ans+=cnt[0];
       cout<<ans<<"\n";
    }
    return 0;
}