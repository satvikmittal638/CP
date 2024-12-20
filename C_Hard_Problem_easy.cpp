#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int m,a,b,c;cin>>m>>a>>b>>c;
       int row1=0,row2=0;
       row1+=min(a,m);
       row2+=min(b,m);
       row1+=min(c,max(m-a,0));
       c=max(0,c-max(m-a,0));
       row2+=min(c,max(m-b,0));
       cout<<row1+row2<<"\n";

    }
    return 0;
}