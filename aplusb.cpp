#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const int MAX=5*1e4+2;
const int MAX_SIZE=1<<18;
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
    int n;cin>>n;
    map<int,int> cnta;
    vector<int> a(n);for(auto &i:a) {cin>>i;cnta[i]++;}
    vector<cd> fa(MAX_SIZE,0);
    // shift origin to MAX
    for(int i=0;i<n;i++){
        fa[MAX+a[i]]+=1;
    }
    fft(fa,0);
    for(int i=0;i<fa.size();i++){
        fa[i]*=fa[i];
    }
    fft(fa,1);
    vector<ll> cntSums(fa.size(),0);// sum a[i]+a[j] is stored as 2*MAX+a[i]+a[j] 
    for(int i=0;i<fa.size();i++){
        cntSums[i]=llround(fa[i].real());
        ll sum=i-2*MAX;
        if(sum%2==0 && cntSums[i]>0 && cnta.count(sum/2)) {
            cntSums[i]-=cnta[sum/2]; // to remove i=j case from even sums((i,i) was counted once only, not twice)
        }
    }
    ll ans=0ll,cnt0=count(all(a),0);
    for(int i = 0; i < n; i++) {
            ans += cntSums[a[i] + 2*MAX];
            
            // remove pairs where u == i or v == i
            if (a[i] == 0) {
                ans -= 2 * (cnt0 - 1);
            } else {
                ans -= 2 * cnt0;
            }
        }
    cout<<ans<<'\n';
     

    return 0;
}