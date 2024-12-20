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
       ll n,k;cin>>n>>k;
       deque<ll> dq(n);
       for(int i=0;i<n;i++){
        cin>>dq[i];
       }
       while(dq.size()>1 && k>0){
        ll mn=min(dq.front(),dq.back());
        // always have issues in off by 1 things like these
        if(k<2*mn){
            dq.front()-=k/2 + (k&1); // front ships deals 1 extra damage if k is odd
            dq.back()-=k/2;
            k=0;
        }
        else{
            dq.front()-=mn;
            dq.back()-=mn;
            k-=2*mn;
        }
        if(dq.front()==0) dq.pop_front();
        if(dq.back()==0) dq.pop_back();
       }
       int ans=(n-dq.size()) + (dq.size() && dq.front()<=k); // explicit handling for single ship if left
       cout<<ans<<"\n";
    }
    return 0;
}