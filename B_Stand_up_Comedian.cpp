#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int a[5];cin>>a[1]>>a[2]>>a[3]>>a[4];
       /*
sequence looks like 1,1..1,2,3,2,3,..2,3,2,2,2,2..2,4,4..4
alternating 2 and 3 doesn't change my mood score
       */
       int cnt=a[1]+2*min(a[2],a[3])+
       min(a[1]+1,abs(a[2]-a[3])+a[4]);
       if(a[1]==0){
        cnt=1;
       }
       cout<<cnt<<"\n";
       
    }
    return 0;
}