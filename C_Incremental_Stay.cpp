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
       vector<ll> a(2*n+1,0ll);for(int i=1;i<=2*n;i++)cin>>a[i];
       vector<ll> p(2*n+1,0ll),p_even(2*n+1,0ll),p_odd(2*n+1,0ll);
       for(int i=1;i<=2*n;i++){
        p[i]=p[i-1]+a[i];
        if(i%2==0) {
            p_even[i]=p_even[i-2]+a[i];
            p_odd[i]=p_odd[i-1];
        }
        else {
            p_odd[i]=p_odd[i-2]+a[i];
            p_even[i]=p_even[i-1];
        }
       }
       for(int k=1;k<=n;k++){
        ll ans=(p[2*n]-p[2*n-k])-(p[k]);
        // all indices with same parity as (k+1) are exits-> add
        // opposite parity are entrances-> subtract
        if((k+1)%2==0){
            ans+=p_even[2*n-k]-p_even[k];
            ans-=p_odd[2*n-k]-p_odd[k];
        }
        else{
            ans+=p_odd[2*n-k]-p_odd[k];
            ans-=p_even[2*n-k]-p_even[k];
        }
        cout<<ans<<' ';
       }
       cout<<'\n';
    }
    return 0;
}