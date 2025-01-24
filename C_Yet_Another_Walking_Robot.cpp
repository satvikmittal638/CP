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
       s=" "+s;
       int cntR_L=0, cntD_U=0;
       int lans=-1,rans=-1;
       map<pair<int,int>,int> mp; // (cntRL,cntDU)->end index of prefix
       mp[{0,0}]=INT_MAX;// empty prefix
       for(int i=1;i<=n;i++){
        cntR_L+=(s[i]=='R')-(s[i]=='L');
        cntD_U+=(s[i]=='D')-(s[i]=='U');
        int lastInd=mp[{cntR_L,cntD_U}];
        if(lastInd!=0){
            if(lastInd==INT_MAX) lastInd=0;
            if(rans==-1 || rans-lans>i-lastInd){
                rans=i;
                lans=lastInd+1;
            }
        }
        mp[{cntR_L,cntD_U}]=i;// greedily its always better to store the maxm index
       }
       if(rans==-1) cout<<"-1\n";
       else cout<<lans<<" "<<rans<<"\n";
    }
    return 0;
}