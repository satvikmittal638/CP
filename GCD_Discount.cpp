#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> a(n+1),b(n+1);
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) cin>>b[i];
        // preprocessing->build gcd prefix array from a
        vector<long long> prefix(n+1),suffix(n+1);
        prefix[0]=suffix[n]=0; // gcd(0,a)=a
        for(int i=1;i<=n;i++){
            prefix[i]=gcd(prefix[i-1],a[i]);
        }
        // prefix from end=suffix
        suffix[0]=0;
        for(int i=n;i>=1;i--){
            // stored in suffix from 1..n
            suffix[n-i+1]=gcd(suffix[n-i],a[i]);
        }


        long long mxGCD=LLONG_MIN;
        for(int i=1;i<=n;i++){
            /*
            1st half->[1,i-1]
            2nd half->[i+1,n]
            compute: gcd(1st half,b[i],2nd half) for all values of i and find the maxm gcd possible
            */
            long long gcd1stHalf=prefix[i-1],gcd2ndHalf=suffix[n-i],
                    curGCD=gcd(gcd1stHalf,gcd(b[i],gcd2ndHalf));
            mxGCD=max(mxGCD,curGCD);
        }
        cout<<max(mxGCD,prefix[n])<<"\n"; // choose an element out of b or not
    }
    return 0;
}