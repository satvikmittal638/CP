#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n,a,b;cin>>n>>a>>b;
       string s;cin>>s;
       int x=0,y=0,i=0,cnt=0;
       bool isPos=0;
       while(cnt<=1000){
        if(s[i]=='N'){
            y++;
        }
        else if(s[i]=='S'){
            y--;
        }
        else if(s[i]=='E'){
            x++;
        }
        else if(s[i]=='W'){
            x--;
        }
        i++;cnt++;
        if(i>=n) i-=n;
        
        if(x==a && y==b) {cout<<"YES\n";isPos=1;break;}
       }
       if(!isPos)
       cout<<"NO\n";
    }
    return 0;
}