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
       int n,m,p,q;cin>>n>>m>>p>>q;
       cout<<((q*((n-1)/p +1)==m)?"YES":"NO")<<"\n";
    }
    return 0;
}