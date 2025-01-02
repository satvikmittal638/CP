#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int n,k1,k2;cin>>n>>k1>>k2;
    vector<int> a(n),b(n);
    for(auto &i:a) cin>>i;
    for(auto &i:b) cin>>i;
    priority_queue<int> pq;
    for(int i=0;i<n;i++){
        pq.push(abs(a[i]-b[i]));
    }
    int total_op=k1+k2;
    while(total_op--){
        int mx=pq.top();
        pq.pop();
        mx--;
        pq.push(abs(mx));
    }
    ll ans=0ll;
    while(!pq.empty()){
        ll mx=pq.top();
        pq.pop();
        ans+=mx*mx;
    }
    cout<<ans;
    return 0;
}