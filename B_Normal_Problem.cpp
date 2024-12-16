#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       string a;cin>>a;
       reverse(a.begin(),a.end());
       for(int i=0;i<a.length();i++){
        if(a[i]=='p') a[i]='q';
        else if(a[i]=='q') a[i]='p';
       }
       cout<<a<<"\n";
    }
    return 0;
}