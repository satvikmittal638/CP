#include<iostream>
#include<vector>
using namespace std;

int maxDigit(int n){
    int mxD=0;
    while(n){
        mxD=max(n%10,mxD);
        n/=10;
    }
    return mxD;
}

int main()
{
    int n,cnt=0;cin>>n;
    // greedy approach->subtract the largest digit each time to reach 0 in minimum number of steps
   while(n){
        cnt++;
        n-=maxDigit(n);
   }
    cout<<cnt;
    return 0;
}