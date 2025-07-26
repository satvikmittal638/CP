#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    ll tt;cin>>tt;
    while(tt--){
       ll n;cin>>n;
       vector<ll> x(n),y(n);
       map<ll,ll> cnt_x,cnt_x_plus_y;
       for(ll i=0;i<n;i++) {
        cin>>x[i]>>y[i];
        cnt_x[x[i]]++;
        cnt_x_plus_y[x[i]+y[i]]++;
       }
       // get minm x coord with odd ON bulbs
       ll ans_x,ans_y;
       for(auto &[x,cnt]:cnt_x){
        if(cnt%2!=0){
            ans_x=x;
            break;
        }
       }
        // get maxm x+y=c line with odd ON bulbs
       ll sum=LLONG_MIN;
       for(auto &[sum_x_y,cnt]:cnt_x_plus_y){
        if(cnt%2!=0){
            sum=max(sum,sum_x_y);
        }
       }
       ans_y=sum-ans_x;
       cout<<ans_x<<" "<<ans_y<<"\n";

    }
    return 0;
}