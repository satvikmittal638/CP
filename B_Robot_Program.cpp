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
       ll n,x,k;cin>>n>>x>>k;
       string s;cin>>s;
       ll ans=0ll,cur=x,t=0;
       for(int i=0;i<n;i++){
        cur+=(s[i]=='R')-(s[i]=='L');
        t++;
        if(cur==0){
            ans++;
            break;
        }
       }
       if(cur!=0 || k<t){
           cout<<"0\n";
           continue;
        }
        k-=t;
        // now am at 0 for sure
       int d=0,l=0;
       for(int i=0;i<n;i++){
        d+=(s[i]=='R')-(s[i]=='L');
        l++;
        if(d==0) break;
       }
       if(d==0) ans+=(k/l);
    //    cout<<k<<" "<<l<<" ";
       cout<<ans<<"\n";

    }
    return 0;
}