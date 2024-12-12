#include<iostream>
#include<vector>
using namespace std;

 int longestCommonSubstr(string str1, string str2) {
    int n=str1.size(),m=str2.size();
       vector<vector<int> > dp(n+1,vector<int>(m+1,0));
    

       // fill the table row-wise and also maintain lcw
       int lcw=0;
       for(int c=m-1;c>=0;c--){
            for(int r=n-1;r>=0;r--){
               if(str1[r]==str2[c]){
                dp[r][c]=1+dp[r+1][c+1];
               } 
            //    else{
            //     dp[r][c]=0;
            //    }
               lcw=max(lcw,dp[r][c]);
            }
       }
       return lcw;
}


int main()
{
    cout<<longestCommonSubstr("ABCDGH","ACDGHR");
    return 0;
}