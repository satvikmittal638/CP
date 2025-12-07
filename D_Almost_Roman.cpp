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
       int n,q;cin>>n>>q;
       string s;cin>>s;
       // initially consider all ? be replaced with Is
       int base_score=0,total_inc=0,total_same=0,cntq=0;
       for(int i=0;i<n;i++){
        if(s[i]=='X') base_score+=10;
        else if(s[i]=='V') base_score+=5;
        else if(s[i]=='I' || s[i]=='?'){
            if(i<n-1 && (s[i+1]=='X' || s[i+1]=='V')) base_score--;
            else base_score++;
        }
        cntq+=s[i]=='?';
       }
       // now look at each segment of ?
       int i=0;
       while(i<n){
        if(s[i]!='?'){
            i++;
            continue;
        }
        int st=i,end;
        while(i<n && s[i]=='?') i++;

        if(s[i]!='?') end=i-1;
        else end=i;

        // found a valid segment of '?'
        if(s[st]=='?'){
            int eff_len=end-st+1;
            if(st>0 && s[st-1]=='I') eff_len++;
            if(end<n-1 && s[end+1]=='X' || s[end+1]=='V') eff_len++;
            int inc=eff_len/2,same=eff_len%2;
            if(s[end+1]=='X' || s[end+1]=='V') inc--; // already a pair IV/X was there and counted for in the base_score

            total_inc+=inc;
            total_same+=same;
        }

       }


       while(q--){
        int x,v,i;cin>>x>>v>>i;
        int ans=base_score;
        int need=max(cntq-i,0),k=need;

        int take_inc=min(total_inc,k);// increase no. of IV pairs->(II->IV)-->+2
        ans+=take_inc*2;
        k-=take_inc;

        int take_same=min(total_same,k);// keep no. of IV pairs same->(IIV->IVV)-->+4
        ans+=take_same*4;
        k-=take_same;

        ans+=k*6;// decrease no. of IV pairs->(IV->VV)-->+6

        // now account for X(which were earlier considered as Vs only)
        int needX = max(0, need - v);
        ans += needX * 5;
        cout<<ans<<'\n';
       }
    }
    return 0;
}