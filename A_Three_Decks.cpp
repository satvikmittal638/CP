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
       ll a,b,c;cin>>a>>b>>c;
       ll tot=a+b+c;
       ll x,y;
       x=2*(c-b)+(b-a);
       x/=3;
       y=2*x+(b-c);
        a+=y;
        b+=x-y;
        c-=x;
        if((tot==(a+b+c)) && a==b && b==c && x>=y){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}