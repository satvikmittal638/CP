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
       int n;cin>>n;
       vector<int> x(n+1),y(n+1);
       x[0]=y[0]=INT_MIN;
       for(int i=1;i<=n;i++)cin>>x[i]>>y[i];
       sort(all(x));
       sort(all(y));
       //all values in [left median,right median] are optimal
       ll cnt_x=x[(n+2)/2]-x[(n+1)/2]+1;
       ll cnt_y=y[(n+2)/2]-y[(n+1)/2]+1;
       cout<<1ll*cnt_x*cnt_y<<"\n";
    }
    return 0;
}