#include<bits/stdc++.h>
using namespace std;


int main()
{
    int tt;cin>>tt;
    while(tt--){
       int c,m,x;cin>>c>>m>>x;
       int lo=0,hi=(c+m+x)/3;
       while(lo<hi){
        int mid=(lo+hi+1)/2;
        if(m>=mid && c>=mid && (m+c+x)>=3*mid){
            lo=mid;
        }else{
            hi=mid-1;
        }
       }
       cout<<lo<<"\n";
    }
    return 0;
}