#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int l,r,k;cin>>l>>r>>k;
       int cnt=max(r/k-l+1,0);
    //    for(int i=l;i<=r;i++){
    //     if(k*i<=r) cnt++;
    //    }
       cout<<cnt<<"\n";
    }
    return 0;
}