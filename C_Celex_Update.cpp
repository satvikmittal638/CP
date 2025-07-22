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
       ll x1,x2,y1,y2;cin>>x1>>y1>>x2>>y2;
       // all sums [min,max] are achievable
       // maxm sum is moving down then moving right
       // minm sum is moving right then moving down
       cout<<(x2-x1)*(y2-y1)+1<<"\n"; 
    }
    return 0;
}