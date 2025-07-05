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
       string n;cin>>n;
       auto noOfSol=[&](int ni){
        ll ans=0ll;
        for(int ai=0;ai<=9;ai++){
            for(int bi=0;bi<=9;bi++){
                for(int ci=0;ci<=9;ci++){
                    ans+=(ai+bi+ci)==ni;
                }
            }
        }
        return ans;
       };
       ll ans=1ll;
       for(auto d:n){
        ans*=noOfSol(d-'0');
       }
       cout<<ans<<"\n";
    }
    return 0;
}