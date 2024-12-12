#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,m;cin>>n>>m;
    vector<int> x(n),dp(n+1);
    // dp[i] denotes the number of arrays possible with ending index at i(1-indexed)
    dp[0]=0; // no array w/o elts can be formed
    // use 1 based indexing for dp
    for(int i=1;i<=n;i++){
        if(x[i]){

        }
    }

    return 0;
}