#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       int a,va,c,vc,b,vb;cin>>a>>va>>c>>vc>>b;
        int speed=(vc-va)/(c-a);
        vb=(speed>0)?(b*speed):va;
        cout<<vb<<"\n";
    }
    return 0;
}