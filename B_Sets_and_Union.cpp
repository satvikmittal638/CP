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
       int n;cin>>n;
       ll U=0ll;
       vector<ll> sets(n,0ll);
        for(int i=0;i<n;i++){
            int k;cin>>k;
            while(k--){
                int s;cin>>s;
                sets[i]|=(1ll<<s);
            }
            U|=sets[i];
        }
        int ans=0;
        // construct all sets T such that i doesn't belong to T
        // but i belongs to union of all the sets
        for(int i=1;i<=50;i++){
            // unite all sets which don't have i in them
            // denote their union by T
            if((U&(1ll<<i))!=0){
                ll T=0ll;
                for(auto S:sets){
                    if((S&(1ll<<i))==0){
                        T|=S;
                    }
                }
                ans=max(ans,__builtin_popcountll(T));
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}