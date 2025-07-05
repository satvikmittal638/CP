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
       int n,m;cin>>n>>m;
       vector<ll> a(n);for(auto &i:a) cin>>i;
       if(n==1){
        cout<<"0\n";
        continue;
       }
       ll sum=0ll,ans=0ll;
       // flip the largest element to reduce the sum
       priority_queue<ll> mxpq;
       for(int i=m-1;i>=1;i--){
        mxpq.push(a[i]);
        sum+=a[i];
        if(sum>0){
            ans++;
            sum-=2*mxpq.top();
            mxpq.pop();
        }
       }
       sum=0ll;
       priority_queue<ll, vector<ll>, greater<ll>> minpq;
       // flip the smallest element to increase the sum
       for(int i=m;i<n;i++){
        minpq.push(a[i]);
        sum+=a[i];
        if(sum<0){
            ans++;
            sum-=2*minpq.top();
            minpq.pop();
        }
       }
       cout<<ans<<"\n";
    }
    return 0;
}