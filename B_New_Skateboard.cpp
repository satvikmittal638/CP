#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;cin>>s;
    long long dp=0,ndp;
    for(int i=0;i<s.length();i++){
        int lastDig=s[i]-'0';
        int last2Num=(s[i-1]-'0')*10+lastDig;
        ndp=dp+(lastDig%4==0) + i*(last2Num%4==0);
        dp=ndp;
    }
    cout<<dp;
    return 0;
}