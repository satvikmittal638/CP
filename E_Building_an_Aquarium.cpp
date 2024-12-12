#include<bits/stdc++.h>
using namespace std;


bool isPossible(vector<long long>& a,long long h,long long x){
    long long water=0ll;
    for(auto colH:a){
        water+=max(0ll,h-colH);
    } 
    return water<=x;
}

int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n;long long x;cin>>n>>x;
       vector<long long> a(n);for(auto &i:a) cin>>i;
       long long lo=0,hi=INT_MAX;
       while(lo<hi){
        long long mid=lo+(hi-lo+1)/2ll;
        if(isPossible(a,mid,x)){
            lo=mid;
        }else{
            hi=mid-1;
        }
       }
       cout<<lo<<"\n";
    }
    return 0;
}