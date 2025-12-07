#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const ll MOD=1009;
// FFT
using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    ll n = a.size();

    for (ll i = 1, j = 0; i < n; i++) {
        ll bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (ll len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (ll i = 0; i < n; i += len) {
            cd w(1);
            for (ll j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}
int main()
{
fastio;
    ll n,m,k;cin>>n>>m>>k;
    vector<ll> c(m+1,0ll);
    for(ll i=0;i<n;i++){
        ll x;cin>>x;
        c[x]++;
    }
    auto cmp = [](const vector<cd>& a, const vector<cd>& b){
    return a.size() > b.size();   // min-heap
};
    priority_queue<vector<cd>, vector<vector<cd>>, decltype(cmp)> pq(cmp);
    for(int i=1;i<=m;i++){
        if(c[i]==0) continue;
        vector<cd> f(min(c[i],k)+1,1);
        pq.push(f);
    }
    // multiply 2 polynomials with nearest degree
    while(pq.size()>1){
        auto f1=pq.top();pq.pop();
        auto f2=pq.top();pq.pop();
        ll n=1;
        while(n<f1.size()+f2.size()-1) n<<=1;
        f1.resize(n);
        f2.resize(n);
        fft(f1,0);
        fft(f2,0);
        for(ll i=0;i<n;i++) {
            f1[i]*=f2[i];
        }
        fft(f1,1);
        // restrict until x^k only
        if(f1.size()>k+1) f1.resize(k+1);
        // reduce the coefficients modulo mod
        for(int i=0;i<f1.size();i++){
            ll val=llround(f1[i].real())%MOD;
            f1[i]=val;
        }
        pq.push(f1);
    }
    cout<<(llround(pq.top()[k].real()));// coeff of x^k in the final polynomial
    return 0;
}