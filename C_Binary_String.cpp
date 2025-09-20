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
       string s;cin>>s;
       int n=s.length();
       vector<int> cnt0(n,0);
       for(int i=0;i<n;i++){
        cnt0[i]+=s[i]=='0';
        if(i>0) cnt0[i]+=cnt0[i-1];
       }
       int c=count(all(s),'1');
       int ans=INT_MAX;
       if(c==n) ans=0;
       // case 1: c<=(r-l+1)
       // cost=min(cnt0[l,r] s.t. r-l+1=c)
       for(int r=c;r<n;r++){
        ans=min(ans,cnt0[r]-cnt0[r-c]);
       }
       // case 2: c>=(r-l+1)
       // cost = cnt0[l,r] + c - (r-l+1)
       // for each window of length c, we want to minimize cnt0[l,r] - (r-l+1)
       // we will use a multiset to track cnt0[l] - l for l in [0, c-1]
       if (c > 0) {
           multiset<int> ms;
           for(int l=0; l<c; l++) {
               ms.insert(cnt0[l] - l);
           }
           for(int r=c-1; r<n; r++) {
               int cur = cnt0[r] - r - *ms.begin() + c;
               ans = min(ans, cur);
               // slide window: remove leftmost, add next right
               int l_out = r - c + 1;
               ms.erase(ms.find(cnt0[l_out] - l_out));
               if(r+1 < n) {
                   ms.insert(cnt0[r+1] - (r+1));
               }
           }
       }
       cout<<ans<<"\n";



    }
    return 0;
}