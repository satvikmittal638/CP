#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const int MAX=30;
int main()
{
fastio;
// dp[i][j] checks if there exists a permutation of i elts with exactly j subsegments w/o inversion
    vector<vector<bool>> dp(MAX+1,vector<bool>(MAX*(MAX-1)/2+1,0));
    dp[0][0]=1; // base
    for(int i=1;i<=MAX;i++){
        for(int j=0;j<=MAX*(MAX-1)/2;j++){
            for(int m=1;m<=i;m++){
                int cnt=m*(m-1)/2;
                if(j>=cnt && dp[i-m][j-cnt]) dp[i][j]=1;
            }
        }
    }
    int tt;cin>>tt;
    while(tt--){
       int n,k;cin>>n>>k;
       int curCost=n*(n-1)/2-k,curN=n;
       if(!dp[n][curCost]){
        cout<<"0\n";
        continue;
       }
       // backtrack to get a set of values m1,..mp s.t. sum is n
       // and sum of m*(m-1)/2 is n*(n-1)/2-k
       vector<int> segs;
       while(curN){
        for(int m=1;m<=curN;m++){
            int prevCost=curCost-m*(m-1)/2;
            if(dp[curN-m][prevCost]){
                segs.push_back(m);
                curCost=prevCost;
                curN-=m;
                break;
            }
        }
       }
       // construct the permutation
       int cur=n;
       for(auto m:segs){
        for(int i=cur-m+1;i<=cur;i++){
            cout<<i<<' ';
        }
        cur-=m;
       }
       cout<<'\n';

    }
    return 0;
}