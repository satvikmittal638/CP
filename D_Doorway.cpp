#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

#ifndef ONLINE_JUDGE
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
#else
#define error(args...)
#endif
const ll INF=1e10;
int main()
{
fastio;
    int n;cin>>n;
    vector<vector<ll>> ls(n);
    vector<ll> len;
    for(int i=0;i<n;i++){
        ll k,x1,x2;cin>>k>>x1>>x2;
        ll s=0ll;
        ls[i].emplace_back(x1);// no door at start  
        // starting (j+1) doors to the left 
        for(int j=0;j<k;j++){
            ll l;cin>>l;
            s+=l;
            ls[i].emplace_back(x1+s);
        }
        // len is fixed for a row
        len.push_back(x2-x1-s);
    }
    // sweep line
    vector<pair<ll,ll>> starts;
    for(int i=0;i<n;i++){
        for(auto &l:ls[i]){
            starts.emplace_back(l,i);
        }
    }
    sort(all(starts));
    ll ans=0ll;
    multiset<pair<ll,ll>> ends;
    vector<ll> assignedR(n,-1);
    for(auto &[l,ind]:starts){
        // try using this l as a starting point
        // so remove old l, add this new l
        
        ends.erase({assignedR[ind],ind});
        // assign new
        ll newR=l+len[ind]-1;
        assignedR[ind]=newR;
        ends.insert({newR,ind});

        // all layers have been added atleast once
        if(ends.size()==n){
            auto [minR,i]=*ends.begin();
            ans=max(ans,minR-l+1);
        }
    }
    cout<<ans;
    return 0;
}