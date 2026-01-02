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

int main()
{
fastio;
    ll tt;cin>>tt;
    while(tt--){
       ll n;cin>>n;
       vector<tuple<ll,ll,ll>> lr,rl;// last elt is index
       map<pair<ll,ll>,ll> f;
       for(ll i=0;i<n;i++){
        ll l,r;cin>>l>>r;
        lr.emplace_back(l,r,i);
        rl.emplace_back(r,l,i);
        f[{l,r}]++;
    }
        vector<ll> ans(n,0);

       // increasing by l, then decreasing by r
       sort(all(lr),[](auto t1,auto t2){
        if(get<0>(t1)!=get<0>(t2)) return get<0>(t1)<get<0>(t2);
        return get<1>(t1)>get<1>(t2);
       });
       // decreasing by r, then increasing by l
       sort(all(rl),[](auto t1,auto t2){
        if(get<0>(t1)!=get<0>(t2)) return get<0>(t1)>get<0>(t2);
        return get<1>(t1)<get<1>(t2);
       });


       // for a i, answers are intervals of form [L,l[i]) U (r[i],R] where L=max(predictors l[j]) , R=min(predictors r[j])
       // by sorting we ensure that all candidates lie on the prefix [1,i-1] when processing i
       // process (r[i],R] first
       // use lr and mallain on the fly sorting for r
       set<ll> st_r;
       for(ll i=0;i<n;i++){
        auto [l,r,ind]=lr[i];
        // multiple identical intervals same as the itvl at this idx, so ans is ultimately 0
        if(f[{l,r}]>1) {
            st_r.insert(r);
            continue;
        }

        auto it=st_r.lower_bound(r);
        if(it!=st_r.end()){
            ll R=*it; // get minm r[i]>=r
            ans[ind]+=R-r;
        }
        st_r.insert(r);
       }

       // process [L,l[i])
       // use rl
       set<ll> st_l;
       for(ll i=0;i<n;i++){
           auto [r,l,ind]=rl[i];
        if(f[{l,r}]>1){
            st_l.insert(l);
            continue;
        }

        // get maxm l[i]<=l
        auto it=st_l.upper_bound(l);// first elt>l[i]
        if(it!=st_l.begin()){
            it--;// last elt<=l[i]
            ll L=*it;
            ans[ind]+=l-L;
        }
        st_l.insert(l);
       }

       for(auto e:ans) cout<<e<<'\n';
    }
    return 0;
}