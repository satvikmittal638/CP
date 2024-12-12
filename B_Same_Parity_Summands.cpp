#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n,k;cin>>n>>k;
       if(n>=k && (n%k)%2==0){
        cout<<"YES\n";
        for(int i=1;i<k;i++){
            cout<<n/k<<" ";
        }
        cout<<n/k + n%k<<"\n";
       }else{
        cout<<"NO\n";
       }
    }
    return 0;
}