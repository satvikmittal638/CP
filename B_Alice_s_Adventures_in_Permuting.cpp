#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n,c,b;cin>>n>>b>>c;
       if(b==0){
        if(c>=n) cout<<n;
        else if(c==n-1 || c==n-2) cout<<n-1;
        else cout<<-1;
       }
       else{
        if(c>=n) cout<<n;
        else cout<<n-((n-c-1)/b + 1);
       }
       cout<<"\n";
    }
    return 0;
}