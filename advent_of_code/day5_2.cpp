#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    vector<pair<ll,ll>> ranges;
    string s;

    while (getline(cin, s)) {
        if (s.empty()) break;
        ll L, R;
        sscanf(s.c_str(), "%lld-%lld", &L, &R);
        ranges.emplace_back(L, R);
    }
    // ascending by L, then descending by R
    sort(all(ranges),[&](auto p1,auto p2){
        if(p1.first!=p2.first) return p1.first<=p2.first;
        else return p1.second>=p2.second;
    });
    ll ans=0ll;
    vector<pair<ll,ll>> merged;
    for(auto &p : ranges) {
        if(merged.empty() || p.first > merged.back().second) {
            // no overlap, add new interval
            merged.push_back(p);
        } else {
            // overlap, extend the end of the last interval
            merged.back().second = max(merged.back().second, p.second);
        }
    }
    // merged is disjoint set of intervals
    for(auto &[l,r]:merged){
        ans+=r-l+1;
    }
    cout<<ans;
    return 0;
}