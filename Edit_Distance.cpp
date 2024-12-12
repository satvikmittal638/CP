#include<iostream>
#include<vector>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.length(),m=s2.length();
    vector<vector<int> > dp(m+1,vector<int>(n+1));
    // initialisation of last row
    for(int c=0;c<=n;c++){
        dp[m][c]=m-c+1; // Edit dist between empty string and full string of length n-c+1
    }
    // initialisation of last col
    for(int r=0;r<=m;r++){
        dp[r][n]=n-r+1; // Edit dist between empty string and full string of length n-c+1
    }
    // row-wise filling
    for(int r=m-1;r>=0;r--){
        for(int c=n-1;c>=0;c--){
            if(s1[c]==s2[r]) dp[r][c]=dp[r+1][c+1]; //  equal characters dont change the ED
    /*
    now 3 possibilities:
    i)replace s1[c] by s2[r] and hence the start becomes equal
    ii)delete s1[c] and proceed ahead with start as s1[c+1] and s2[r]
    iii)delete s2[r] and proceed ahead with start s1[c] and s2[r+1] 

    Take minimum of all these 3 possibilities 
    */
            else dp[r][c]=1+min(dp[r+1][c+1],min(dp[r][c+1],dp[r+1][c]));
        }
    }
    cout<<dp[0][0];
    return 0;
}