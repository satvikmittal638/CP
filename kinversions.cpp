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
    string s;cin>>s;
    vector<cd> fa,fbrev;
    int n=1;
    while(n<2*s.size()-1)n<<=1;
    fa.assign(n,0);
    fbrev.assign(n,0);
    for(int i=0;i<s.size();i++){
        if(s[i]=='A'){
            fa[i]=1;
        }
        else{
            fbrev[s.size()-1-i]=1;
        }
    }
    fft(fa,0);
    fft(fbrev,0);
    for(int i=0;i<fa.size();i++){
        fa[i]*=fbrev[i];
    }
    fft(fa,1);
    for(int k=1;k<s.size();k++){
        int ans=llround(fa[(s.size()-1)+k].real());
        cout<<ans<<'\n';
    }
    return 0;
}