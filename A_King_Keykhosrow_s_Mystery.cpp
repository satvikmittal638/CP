#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int a,b;cin>>a>>b;
       int ans=lcm(a,b);
       cout<<ans<<"\n";
    }
    return 0;
}