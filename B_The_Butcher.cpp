#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()

int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<pair<ll,ll>> prs;
       for(auto &i:prs) cin>>i.first>>i.second;
       multiset<pair<ll,ll>> msh,msw;
       for(int i=0;i<n;i++){
        msh.insert(prs[i]);
        msw.emplace(prs[i].second,prs[i].first);
       }
       // if the 1st cut was vertical, piece of maxm h must be stacked together SBS
       auto [h,w]=*msh.rbegin();
       msh.erase(--msh.end());
       msw.erase(msw.find({w,h}));
       while(msh.size()){
        // stack pieces with maxm h
        while(msh.size() && msh.rbegin()->first==h){
            w+=msh.rbegin()->second;
            msw.erase(msw.find({msh.rbegin()->second,msh.rbegin()->first}));
            msh.erase(--msh.end());
        }
        //
       }
    }
    return 0;
}