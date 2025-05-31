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
       int n,l,r;cin>>n>>l>>r;
       map<int,int> cnt_l,cnt_r;
       for(int i=0;i<l;i++){
        int c;cin>>c;
        cnt_l[c]++;
       }
       for(int i=0;i<r;i++){
        int c;cin>>c;
        cnt_r[c]++;
       }
       ll ans=0ll;
       // do initial pairing up
       for(auto &[c,cnt]:cnt_l){
        int paired=min(cnt,cnt_r[c]);
        cnt-=paired;
        cnt_r[c]-=paired;
        if(cnt<cnt_r[c]) swap(cnt,cnt_r[c]);
       }
       // now no. of left socks are atleast as much as no. of right socks
       // self pairing by L->R conversions
       int rem=0;
       for(auto &[c,cnt]:cnt_l){
        int extra=cnt-cnt_r[c];
        ans+=extra/2;
        cnt-=extra;
        rem+=cnt+cnt_r[c];
       }
       ans+=rem;
  
       // match the colors
       cout<<ans<<"\n";

    }
    return 0;
}