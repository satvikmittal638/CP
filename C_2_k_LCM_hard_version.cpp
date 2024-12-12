#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n,k;cin>>n>>k;
       int a,b,c;
       n=n-(k-3);
       if(n%2!=0){
        a=b=n/2;c=1;
       }else{
        if(n%4==0){
            a=b=n/4;c=n/2;
        }else{
            a=b=n/2-1;c=2;
        }
       }
        cout<<a<<" "<<b<<" "<<c<<" ";
        for(int i=1;i<=k-3;i++){
            cout<<1<<" ";
        }
        cout<<"\n";
    }
    return 0;
}