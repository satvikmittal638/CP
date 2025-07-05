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
       int ans=0;
       for(int d=1;d<=n/2;d++){
        int successfullChecks=0;
        for(int l=0;l<n-d;l++){
            successfullChecks+=(s[l]==s[l+d]) || (s[l]=='?') || (s[l+d]=='?');
            // drop 1 unecessary condition
            if(l-d>=0) successfullChecks-=(s[l-d]==s[l]) || (s[l-d]=='?') || (s[l]=='?');
            // update the ans if the current substr is a tandem rpt
            if(successfullChecks==d) ans=2*d;
        }
       }
       cout<<ans<<"\n";
    }
    return 0;
}