#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int n;cin>>n;
    vector<ll> a(n);for(auto &i:a) cin>>i;
    ll sum=accumulate(all(a),0ll);
    sort(all(a));
    int m;cin>>m;
    for(int i=0;i<m;i++){
        ll ans=LLONG_MAX;
        ll x,y,lo,hi;cin>>x>>y;
        // case-1:sum-y<=a[j]<=x -> x+y-sum
        lo=sum-y,hi=x;
        auto it_l=lower_bound(all(a),lo);
        if (it_l != a.end() && *it_l <= hi) ans=min(ans,x+y-sum);


        // case-2: first(i.e. minm a[j]) a[j]>=max(x,sum-y) --> y-sum+a[j] 
        lo=max(x,sum-y);
        it_l=lower_bound(all(a),lo);
        if(it_l!=a.end()) ans=min(ans,y-sum+*it_l);

        // case-3: x<=a[j]<=sum-y --> 0
        lo=x,hi=sum-y;
        it_l=lower_bound(all(a),lo);
        if (it_l != a.end() && *it_l <= hi) ans=min(ans,0ll);

        // case-4: last(i.e. maxm a[j]) a[j]<=min(x,sum-y)--> x-a[j]
        hi=min(x,sum-y);
        auto it_r=upper_bound(all(a),hi); // first iterator s.t. a[j]>hi
        if(it_r!=a.begin()){
            it_r--;
            ans=min(ans,x-*it_r);
        }
        cout<<ans<<"\n";
    }
    return 0;
}