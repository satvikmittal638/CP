#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int k,n;cin>>k>>n;
    vector<ll> a(n);for(auto &i:a) cin>>i;
    sort(all(a));
    auto isSafe = [&](ll m) {
        auto it_end = lower_bound(all(a), m);  // Find the first index i such that a[i] >= m
        ll children_supplied_by_large = (a.end() - it_end)*m;
        ll required_children = k * m - children_supplied_by_large;
        if (required_children <= 0) return true;  // If councils can already be filled by large elements
        ll sum = accumulate(a.begin(), it_end, 0ll);  // Total sum of small elements(a[i]<m)
        return sum >= required_children;
    };

    ll lo=a[0],hi=accumulate(all(a),0ll);
    while(lo<hi){
        ll mid=(lo+hi+1)/2;
        if(isSafe(mid)){
            lo=mid;
        }else{
            hi=mid-1;
        }
    }
    cout<<lo;
    return 0;
}