#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n);
        long long initSum=0;
        for(int i=0;i<n;i++) {
            cin>>a[i];
            initSum+=i%2==0?a[i]:0; // add even indexed elts only
        }
        // use kadane's algo to find maximum difference between original sum and reversed sum
        long long diff1=0,curSum=0;
        for(int i=0;i<n-1;i+=2){
            curSum+=a[i+1]-a[i];
            diff1=max(diff1,curSum);
            if(curSum<0) curSum=0;
        }
        long long diff2=0;curSum=0;
        for(int i=1;i<n-1;i+=2){
            curSum+=a[i]-a[i+1];
            diff2=max(diff2,curSum);
            if(curSum<0) curSum=0;
        }
        initSum+=max(diff1,diff2);
        cout<<initSum<<"\n";
    }
    return 0;
}