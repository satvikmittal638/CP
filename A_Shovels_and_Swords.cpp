#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int a,b;cin>>a>>b;
       if(a>1 && b>1) cout<<(a+b)/3;
       else cout<<0;
       cout<<"\n";
    }
    return 0;
}