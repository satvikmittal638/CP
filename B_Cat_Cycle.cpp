#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n,k;cin>>n>>k;
       k--; // at kth hour, we would have made k-1 jumps
       int ans;
       if(n%2==0){
        ans=k%n + 1;// make 1-indexed
       }else{
        int f=n/2; // n/2 and (n-1)/2 have the same floor value
        ans=(k/f + k)%n + 1; //make 1-indexed
       }
       cout<<ans<<"\n";
    }
    return 0;
}