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
    int s=accumulate(all(a),0);
    // check beforehand if the sum is possible or not
    if(s%2!=0){
        cout<<0;
        return 0;
    }
    // Use DP to check is s/2 sum can be formed
    bitset<200006> dp; // dp[i] denotes if sum i can be formed
    dp[0]=1;
    for(auto i:a){
        dp|=dp<<i;
    }
    if(!dp[s/2]){
        cout<<0;
        return 0;
    }
    //
    auto cntOdd=[&](){
        int ans=0;
        for(int i=0;i<n;i++) ans+=(a[i]%2);
        return ans;
    }; 
    // until the sum is even and all elements are also even
    while(accumulate(all(a),0)%2==0 && cntOdd()==0){
        for(int i=0;i<n;i++) a[i]/=2;
    }
    cout<<"1\n";
    for(int i=0;i<n;i++){
        if(a[i]%2!=0) {
            cout<<i+1;
            break;
        }
    }

    return 0;
}