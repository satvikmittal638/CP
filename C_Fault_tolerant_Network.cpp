#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()


ll bestCand(vector<ll> &vals,ll cur){
    ll minInd=-1,minCost=LLONG_MAX;
    for(ll i=0;i<vals.size();i++){
        if(abs(vals[i]-cur)<minCost){
            minCost=abs(vals[i]-cur);
            minInd=i;
        }
    }
    return minInd;
}

int main()
{
fastio;
    ll tt;cin>>tt;
    while(tt--){
       ll n;cin>>n;
       vector<ll> a(n),b(n);
       for(auto &i:a) cin>>i;
       for(auto &i:b) cin>>i;
       // connect a[0] to b[0],b[n-1] or b[j] s.t. |a[0]-b[j]| is minm, same goes for a[n-1]
       // total 3X3=9 cases
       // for each case, if we didn't cover b[0] or b[n-1], use bestA for them respectively
        vector<ll> ch1={0,bestCand(b,a[0]),n-1};// choices for a[0]
        vector<ll> ch2={0,bestCand(b,a[n-1]),n-1};// choices for a[n-1]
        ll best=LLONG_MAX;
        for(auto v1:ch1){
            for(auto v2:ch2){
                ll cur_ans=abs(a[0]-b[v1])+abs(a[n-1]-b[v2]);
                // b[0] is unused
                if(v1>0 && v2>0){
                    cur_ans+=abs(b[0]-a[bestCand(a,b[0])]);
                }
                if(v1<n-1 && v2<n-1){
                    cur_ans+=abs(b[n-1]-a[bestCand(a,b[n-1])]);
                }
                best=min(best,cur_ans);
            }
        }
        cout<<best<<"\n";

    }
    return 0;
}