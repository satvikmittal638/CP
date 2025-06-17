#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

long long modexp(long long base, long long exp, long long mod) {
    long long res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

int main()
{
    const ll MOD=998244353;
fastio;
    ll tt;cin>>tt;
    while(tt--){
       ll n;cin>>n;
       vector<ll> p(n),q(n);for(auto &i:p) cin>>i;
       for(auto &i:q) cin>>i;
       vector<ll> p_max(n),q_max(n);
       p_max[0]=p[0];
       q_max[0]=q[0];
       for(ll i=0;i<n;i++){
        if(p[p_max[i-1]]<p[i]){
            p_max[i]=i;
        }
        if(q[q_max[i-1]]<q[i]){
            q_max[i]=i;
        }
       }
       for(int i=0;i<n;i++){
        ll ans;
        if(p[p_max[i]]>q[q_max[i]]){
            int ind=p_max[i];
            ans=(modexp(2,p[ind],MOD)+modexp(2,q[i-ind],MOD))%MOD;
        }
        else if(q[q_max[i]]>p[p_max[i]]){
            int ind=q_max[i];
            ans=(modexp(2,q[ind],MOD)+modexp(2,p[i-ind],MOD))%MOD;
        }
        else{
            int ind1=p_max[i],ind2=q_max[i];
            // choose ind1
            if(q[i-ind1]>=p[i-ind2]){
                ans=(modexp(2,p[ind1],MOD)+modexp(2,q[i-ind1],MOD))%MOD;
            }
            // choose ind2
            else{
                ans=(modexp(2,q[ind2],MOD)+modexp(2,p[i-ind2],MOD))%MOD;
            }
        }
        cout<<ans<<"\n";
       }
    }
    return 0;
}