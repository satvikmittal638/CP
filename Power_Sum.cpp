#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

// FFT
using cd = complex<double>;
const double PI = acos(-1);
void fft(vector<cd> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
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
    int n,s,k;cin>>n>>s>>k;
    vector<int> c(n),v(n);
    for(int i=0;i<n;i++){
        cin>>c[i]>>v[i];
    }
     auto cmp = [](const vector<cd>& a, const vector<cd>& b){
    return a.size() > b.size();   // min-heap
};
    priority_queue<vector<cd>, vector<vector<cd>>, decltype(cmp)> pq(cmp);
    for(int i=0;i<n;i++){
        vector<cd> f(c[i]+1,0);
        f[0]=f[c[i]]=1;
        pq.push(f);
    }
    while(pq.size()>1){
        auto f1=pq.top();pq.pop();
        auto f2=pq.top();pq.pop();
        int sz=1;
        while(sz<f1.size()+f2.size()-1) sz<<=1;
        f1.resize(sz);f2.resize(sz);
        fft(f1,0);
        fft(f2,0);
        for(int i=0;i<sz;i++) f1[i]*=f2[i];
        fft(f1,1);
        if(sz>s+1) f1.resize(s); // keep upto x^s only
        pq.push(f1);
    }
    auto f=pq.top();// coeff(x^p) gives no. of subsets with cost sum=p
    // but we need the sum of v[i] vals of each such subset

    return 0;
}