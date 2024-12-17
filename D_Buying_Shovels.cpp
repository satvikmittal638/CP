#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n,k;cin>>n>>k;
       int mxD=INT_MIN;
       for(int d=1;d*d<=n;d++){
        if(n%d==0){
            int d1=d,d2=n/d;
            if(d1<=k) mxD=max(mxD,d1);
            if(d2<=k) mxD=max(mxD,d2);
        }
       }
       cout<<n/mxD<<"\n";
    }
    return 0;
}