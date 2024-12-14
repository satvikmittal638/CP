#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       long long n,x,y,r,b,p,score;cin>>n>>x>>y;
       r=n/x,b=n/y,p=n/lcm(x,y);
       r-=p;b-=p;
       score=n*r - r*(r-1)/2 - b*(b+1)/2;
       cout<<score<<"\n";
    }
    return 0;
}