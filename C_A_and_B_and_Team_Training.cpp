#include<bits/stdc++.h>
using namespace std;



int main()
{
    int n,m;cin>>n>>m;
    int lo=0,hi=(n+m)/3;
    auto isPos=[&](int k){
        return n>=k && m>=k && n+m>=3*k;
    };
    while(lo<hi){
        int mid=(lo+hi+1)/2;
        if(isPos(mid)){
            lo=mid;
        }else{
            hi=mid-1;
        }
    }
    cout<<lo;
    return 0;
}