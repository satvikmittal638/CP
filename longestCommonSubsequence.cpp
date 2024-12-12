#include<iostream>
#include<vector>
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(),m=text2.size();
        vector<vector<int> > dp(m+1,vector<int>(n+1,0)); // dp[m+1][n+1] -> dp[i][j] denotes longest common subseq starting at text2[i] and text1[j]
        // row-wise filling
        for(int r=m-1;r>=0;r--){
            for(int c=n-1;c>=0;c--){
                if(text1[c]==text2[r]) dp[r][c]=1+dp[r+1][c+1];
                else dp[r][c]=max(dp[r+1][c],dp[r][c+1]); // skip ao or bo and get maximum ans of both the cases
            }
        }
        // TODO:printing the longest common subsequence

        return dp[0][0];
}

int main()
{
    cout<<longestCommonSubsequence("abcde","ace");
    return 0;
}