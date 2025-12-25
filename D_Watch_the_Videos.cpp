#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    ll n,m;cin>>n>>m;
    multiset<ll> msa;
    for(int i=0;i<n;i++){
        ll x;cin>>x;
        msa.insert(x);
    }
    ll curMemory=0ll,ans=0ll;
    while(msa.size()){
        // get largest video which can fit into memory
        // largest a[i]<=m-curMemory
        auto it=msa.upper_bound(m-curMemory);
        if(it!=msa.begin()){
            it--;
            // put it on download and watch the other video in the memory(this time is masked in downloading of the other movie)
            curMemory=0; // delete the other video after watching from memory
            curMemory+=*it;
            ans+=*it;
            msa.erase(it);
        }
        // no a[i] <= m-curMemory
        // compulsorily watch the only video in the memory
        else{
            ans++;
            curMemory=0; // delete it
        }
    }
    cout<<ans+1; // watch last video in memory compulsorily
    return 0;
}