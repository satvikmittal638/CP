#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n,k;cin>>n>>k;
       vector<int> ctr1(31,0);
       for(int i=0;i<n;i++){
        int a;cin>>a;
        for(int i=0;i<31;i++){
            ctr1[i]+=((a&(1<<i))>0);
        }
       }
       int ans=0;
       for(int i=30;i>=0;i--){
        if(ctr1[i]<n && k>0 && ctr1[i]+k>=n){
            k-=n-ctr1[i];
            ctr1[i]=n;
        }
        ans|=(1<<i)*(ctr1[i]==n);
       }
        cout<<ans<<"\n";
    }
    return 0;
}