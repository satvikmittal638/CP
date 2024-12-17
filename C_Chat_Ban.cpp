#include<bits/stdc++.h>
using namespace std;
long long sqrt_bs(long long n) {
    long long lo = 0, hi = n, mid, res = 0;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        // to prevent overflow don't use mid*mid<=n condition
        if (mid <= n/mid) {
            res = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return res;
}


int main()
{
    int tt;cin>>tt;
    while(tt--){
       long long k,x;cin>>k>>x;
       long long sum=k*(k+1)/2,ans;
       if(x<=sum){
        long long z=(sqrt_bs(1+8*x)-1)/2,
                lo=z*(z+1)/2;
        if(x>lo){
            ans=z+1;
        }
        // x==lo
        else{
            ans=z;
        }
       }
       else if(sum<x && x<=k*k){
        long long a=x-sum,
                r=((2*k+2)-sqrt_bs((2*k+1)*(2*k+1)-8*a))/2,
                lo=sum+r*k-r*(r+1)/2;
        if(x>lo) ans=k+r+1;
        else ans=k+r;
        cout<<r<<" ";
        
       }else{
        ans=2*k-1;
       }
       cout<<ans<<"\n";
    }
    return 0;
}