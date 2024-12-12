#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n,k;cin>>n>>k;
       vector<int> a(n);for(auto &i:a) cin>>i;
       sort(a.rbegin(),a.rend());
       int sum=0;
       for(int i=0;i<n;i++){
        if(sum+a[i]<=k) sum+=a[i];
        else break;
       }
       int ans=k-sum;
       cout<<ans<<"\n";
    }
    return 0;
}