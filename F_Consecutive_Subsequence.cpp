#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int n;cin>>n;
    vector<int> a(n);for(auto &i:a) cin>>i;
    // dp[i] is the length of consecutive LIS ending with value i
    map<int,int> dp;
    dp[a[0]]=1;
    for(int i=1;i<n;i++){
        dp[a[i]]=dp[a[i]-1]+1;
    }
    int ans=0,last;
    for(auto &[elt,val]:dp){
        if(ans<val){
            ans=val;
            last=elt;
        }
    }

    cout<<ans<<"\n";
    int j=0;
    for(int i=last-ans+1;i<=last;i++){
        while(j<n && a[j]!=i) j++;
        cout<<j+1<<" ";
    }
    return 0;
}