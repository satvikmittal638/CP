#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       string s;cin>>s;
       // segment like 1..10 can have all 1s removed
       int i=0,cnt0=0,cnt1=0;
       // find leading 0s
       while(i<n && s[i]=='0'){
        i++;
        cnt0++;
       }
       // find trailing 1s
       i=n-1;
       while(i>=0 && s[i]=='1'){
        i--;
        cnt1++;
       }
       cnt0+=(n-(cnt1+cnt0))>0; // everything thats left reduces to 0
       string ans;
       ans.append(cnt0,'0');
       ans.append(cnt1,'1');
       cout<<ans<<"\n";
    }
    return 0;
}