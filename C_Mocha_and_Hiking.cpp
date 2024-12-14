#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<int> a(n);for(auto &i:a) cin>>i;
       if(a[0]==1){
        cout<<n+1<<" ";
        for(int i=1;i<=n;i++) cout<<i<<" ";
        cout<<"\n";
       }
       else if(a[n-1]==0){
        for(int i=1;i<=n+1;i++) cout<<i<<" ";
        cout<<"\n";
       }
       else{
        int i=0;
        while(i<n-1){
            if(a[i]==0 && a[i+1]==1) break;
            i++;
        }
        i++; // make 1 indexed
        for(int j=1;j<=i;j++){
            cout<<j<<" ";
        }
        cout<<n+1<<" ";
        for(int j=i+1;j<=n;j++){
            cout<<j<<" ";
        }
        cout<<"\n";
       }
    }
    return 0;
}