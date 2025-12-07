#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const int MAX=2*1e5;
const int MAX2=2*1e6+1;
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
    int n,x,y;cin>>n>>x>>y;
    vector<int> a(n+1);for(auto &i:a) cin>>i;
    vector<cd> fa(MAX+1,0),fnega(MAX+1,0);
    // shift origin to MAX to store -ve numbers as well
    for(int i=0;i<=n;i++){
        fa[a[i]]=1;
        fnega[MAX-a[i]]=1;
    }
    int N=1;
    while(N<fa.size()+fnega.size()-1) N<<=1;
    fa.resize(N);fnega.resize(N);
    fft(fa,0);
    fft(fnega,0);
    for(int i=0;i<fa.size();i++){
        fa[i]*=fnega[i];
    }
    fft(fa,1);
    
    vector<int> lens;// all possible laps
    // take only non- -ve differences
    for(int i=MAX+1;i<fa.size();i++){
        if(llround(fa[i].real())>0)
            lens.push_back(2*(i-MAX+y));//only rectangular run
    }
    vector<int> ans(MAX2,-1);
    // mark off by larger nos first
    for(int i=lens.size()-1;i>=0;i--){
        for(int j=lens[i];j<MAX2;j+=lens[i]){
            if(ans[j]==-1) ans[j]=lens[i];
        }
    }
    int q;cin>>q;
    while(q--){
        int l;cin>>l;
        cout<<ans[l]<<' ';
    }
    return 0;
}