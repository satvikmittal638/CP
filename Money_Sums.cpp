#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
int main()
{
    int n;cin>>n;
    vector<int> x(n);for(auto &i:x) cin>>i;
    long long sum=accumulate(x.begin(),x.end(),0);
    vector<bool> dp(sum+1);
    dp[0]=1;
    for (auto coin:x) {
        for (int s = sum; s >= 0; s--) {
// if given sum is possible,then another sum(given sum+any coin) is also possible
            if (s+coin<=sum && dp[s]) dp[s+coin] = 1;
        }
    }
    vector<long long> sums;
    for(int s=1; s<=sum; s++){
        if(dp[s]) sums.push_back(s);
    }
    cout<<sums.size()<<"\n";
    for(auto s:sums) cout<<s<<" ";



    return 0;
}