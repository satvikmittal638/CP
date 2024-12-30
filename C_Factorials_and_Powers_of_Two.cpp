#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()


int main()
{
fastio;
    // precompute all factorials till 14!
    ll fact[15];
    fact[0]=1;
    for(int i=1;i<=14;i++){
        fact[i]=fact[i-1]*i;
    }

    int tt;cin>>tt;
    while(tt--){
       ll n;cin>>n;
       int ans=INT_MAX;
       // iterate all subsets of fact[]
        for(int mask=0;mask<(1<<15);mask++){
            ll curFactSum=0ll;
            int cntF=0;
            for(int i=0;i<15;i++){
                if(mask&(1<<i)){
                    curFactSum+=fact[i];
                    cntF++;
                }
            }
            ll left=n-curFactSum;
            if(left>=0){
                ans=min(ans,cntF+(int)__builtin_popcountll(left));
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}