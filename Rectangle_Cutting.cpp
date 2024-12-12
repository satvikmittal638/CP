#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main()
{
    int a,b;cin>>a>>b;
    // a+1 and b+1 size to make based indexing
    vector<vector<int> > dp(a+1,vector<int>(b+1,INT_MAX));
    // fill row-wise
    for(int r=1;r<=a;r++){
        for(int c=1;c<=b;c++){
           if(r==c) dp[r][c]=0;
           else{
            // cut vertically from k=1...c-1 and get minimum
            for(int k=1;k<c;k++){
                // mak vertical cut at k to break into 2 tiles of same row size but col size of k and c-k
                dp[r][c]=min(dp[r][c],1+dp[r][c-k]+dp[r][k]);
            }

            // cut horizontally from k=1...c-1 and get minimum
            for(int k=1;k<r;k++){
                // make horizontal cut at k to break into 2 tiles of same col size but row size of k and r-k
                dp[r][c]=min(dp[r][c],1+dp[k][c]+dp[r-k][c]);
            }

           }
        }
    }
    cout<<dp[a][b];
    
    return 0;
}