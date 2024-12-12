#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;cin>>n>>m;
    // dp[i] denotes number of distinct elts from i...n-1
    vector<int> a(n),dp(n);
    set<int> s;
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    for(int i=n-1;i>=0;i--) {
        s.insert(a[i]);
        dp[i]=s.size();
    }

    while(m--){
        int l;cin>>l;
        l--; // convert to 0 based indexing
        cout<<dp[l]<<"\n";
    }

    return 0;
}