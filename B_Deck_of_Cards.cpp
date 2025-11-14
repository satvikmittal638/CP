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
       // edge case
       if(n==k){
        for(int i=1;i<=n;i++) cout<<'-';
        cout<<'\n';
        continue;
       }
       vector<int> cnt(3,0);
       for(auto e:s) cnt[e-'0']++;
       int lmin=cnt[0]+1,lmax=cnt[0]+cnt[2]+1,rmin=n-cnt[1],rmax=n-(cnt[1]+cnt[2]);
       for(int i=1;i<=n;i++){
        if(lmin<=rmin && i<lmin || i>rmin) cout<<'-';
        else if(lmax<=rmax && lmax<=i && i<=rmax) cout<<'+';
        else cout<<'?';
       }
       cout<<'\n';
    }
    return 0;
}