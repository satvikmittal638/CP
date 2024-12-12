#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,t;cin>>n>>t;
    vector<int> a(n);for(auto &i:a) cin>>i;
    // find maxm window size with sum <=t
    int l=0,r=0,sum=0,maxWin=0;
    while(l<=r && r<n){
        sum+=a[r];
        // reduce window size to bring the sum back under range
        while(l<=r && sum>t){
            sum-=a[l];
            l++;
        }
        maxWin=max(maxWin,r-l+1);
        r++;
    }
    cout<<maxWin;
    return 0;
}