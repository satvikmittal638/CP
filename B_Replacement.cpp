#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       int cnt0=0,cnt1=0;
       // read s
       for(int i=0;i<n;i++){
            char c;cin>>c;
            cnt0+=(c=='0');
            cnt1+=(c=='1');
       }
       /*
        if cnt0 , cnt1>0 then we can always find a '10' or '01' segment
        if '10'/'01' replaced by '0'<--> deletion of a '1'
        if '10'/'01' replaced by '1'<--> deletion of a '0'
       */
      // read r
      bool isPossible=1;
      for(int i=0;i<n-1;i++){
            char c;cin>>c;
            cnt0--;cnt1--;
            if(cnt0<0 || cnt1<0) {cout<<"NO\n";isPossible=0;break;}
            (c=='1'?cnt1:cnt0)++;
       }
       if(isPossible) cout<<"YES\n";

    }
    return 0;
}