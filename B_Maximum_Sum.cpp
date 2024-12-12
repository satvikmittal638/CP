#include<bits/stdc++.h>
using namespace std;

long long powerModulo(long long a, long long b, long long m) {
    long long result = 1;
    a = a % m;  // Update a if it is more than or equal to m

    while (b > 0) {
        // If b is odd, multiply a with the result
        if (b % 2 == 1) {
            result = (result * a) % m;
        }
        // b must be even now
        b = b >> 1;  // Equivalent to b /= 2
        a = (a * a) % m;  // Change a to a^2
    }
    return result;
}

int main()
{
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        vector<long long> a(n);
        for(auto &i:a) cin>>i;
        const long long MOD=1e9+7;
        long long curSum=0,mxSum=0,totalSum=0; // can take empty ssubarray so initialise maxSum with 0
        // kadane's algorithm
        for(int i=0;i<n;i++){
            if(curSum<0) curSum=0;
            curSum+=a[i];
            // curSum=((curSum%MOD)+MOD)%MOD;
            mxSum=max(mxSum,curSum);
            totalSum+=a[i];
            // totalSum=((totalSum%MOD)+MOD)%MOD;
        }
        totalSum = (totalSum%MOD + MOD)%MOD;
        mxSum = (mxSum%MOD + MOD)%MOD;
        long long ans=totalSum + ((mxSum*(powerModulo(2,k,MOD)-1))%MOD);
        ans=((ans%MOD)+MOD)%MOD;
        cout<<ans<<"\n";
    }
    return 0;
}