#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int x;cin>>x;
       int k=(sqrt(8*x+1)-1)/2;
       int del=x-k*(k+1)/2,ans;
       if(del==0){
        ans=k;
       }
       else if(del==k){
        ans=k+2;
       }
       else{
        ans=k+1;
       }
       cout<<ans<<"\n";
    }
    return 0;
}