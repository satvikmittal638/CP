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
       int n,s;cin>>n>>s;
       int ans=0;
       while(n--){
        int dx,dy,x,y;cin>>dx>>dy>>x>>y;
        vector<pair<int,int>> v={{-x,-y},{s-x,-y},{-x,s-y},{s-x,s-y}};
        for(auto [a,b]:v){
            if((dx*a+dy*b)*(dx*a+dy*b)==2*(a*a+b*b)){
                ans++;
            }
        }
       }
       cout<<ans/2<<"\n";
    }
    return 0;
}