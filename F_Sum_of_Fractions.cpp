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
const ll MOD=998244353;
ll fastmmi(ll a) {
    ll res = 1, exp = MOD - 2;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        exp /= 2;
    }
    return res;
}
int main()
{
fastio;
    int n,m;cin>>n>>m;
    vector<ll> a(n),k(m);for(auto &i:a) cin>>i;
    for(auto &i:k) cin>>i;
    // find nsl and nsr for each i
    vector<ll> nsl(n,-1),nsr(n,n);
    // nsl
    vector<ll> st;
    for(int i=0;i<n;i++){
        while(st.size() && a[st.back()]>=a[i]){
            st.pop_back();
        }
        if(st.size()){
            nsl[i]=st.back();
        }
        st.push_back(i);
    }

    // nsr
    st.clear();
    for(int i=n-1;i>=0;i--){
        while(st.size() && a[st.back()]>=a[i]){
            st.pop_back();
        }
        if(st.size()){
            nsr[i]=st.back();
        }
        st.push_back(i);
    }
    vector<ll> inv(n,0);
    for(int i=0;i<n;i++) inv[i]=fastmmi(a[i]);
    // for now lets brute over all k and check our ans
    for(int z=0;z<m;z++){
        ll ans=0ll;
        for(ll i=0;i<n;i++){
            ans+=(((i+1)*(n-i))%MOD * inv[i])%MOD;
            ll cnt=(i-nsl[i])*(nsr[i]-i);
            if(k[z]<a[i]){
                ans+=((((k[z]+1)*cnt)%MOD)*inv[i])%MOD;
            }
            else{
                ans+=(((2+k[z]-a[i])*cnt)%MOD - (cnt*inv[i])%MOD + MOD)%MOD;
            }
            ans%=MOD;
        }
        cout<<ans<<'\n';
    }
    return 0;
}