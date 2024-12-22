#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       ll n,a,b,c;cin>>n>>a>>b>>c;
       ll days=(n/(a+b+c))*3;
       n%=(a+b+c);
       if(n>0){
        n-=a;
        days++;
       }
       if(n>0){
        n-=b;
        days++;
       }
       if(n>0){
        n-=c;
        days++;
       }
       cout<<days<<"\n";
    }
    return 0;
}