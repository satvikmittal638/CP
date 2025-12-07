#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
// FFT
using cd=complex<double>;
const double PI=acos(-1);
// computes the bit reversed number
int reverse(int num,int logn){
    int res=0;
    for(int i=0;i<logn;i++){
        if(num&(1<<i)){
            res|=1<<(logn-1-i); // set the mirror bit
        }
    }
    return res;
}

void fft(vector<cd>& a,bool invert){
    int n=a.size();
    int logn=0;
    while((1<<logn)<n) logn++;

    // sort by bit reversed positions
    for(int i=0;i<n;i++){
        if(i<reverse(i,logn)) swap(a[i],a[reverse(i,logn)]);
    }
    for(int len=2;len<=n;len<<=1){
        double ang=2*PI/len*(invert?-1:1);
        cd wlen(cos(ang),sin(ang));
        // take a block of size len, and apply butterfly transform to it
        for(int i=0;i<n;i+=len){
            cd w(1);
            for(int j=0;j<len/2;j++){
                // first half is E(k)+w*O(k)
                // 2nd half is E(k)-w*O(k)
                cd u=a[i+j],v=a[i+j+len/2]*w;
                a[i+j]=u+v;
                a[i+j+len/2]=u-v;
                w*=wlen;
            }
        }
    }
    // for IDFT
    if(invert){
        for(auto &x:a){
            x/=n;
        }
    }
}

int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       ll N;cin>>N;
       vector<ll> a(N+1),b(N+1);
       for(auto &i:a) cin>>i;
       for(auto &i:b) cin>>i;
       vector<cd> fa(all(a)),fb(all(b));
       ll n=1;
       while(n<fa.size()+fb.size()-1) n<<=1ll; // make n power of 2 nearest to(>=) size of the linear convolution of a and b
       fa.resize(n);
       fb.resize(n);
       fft(fa,0);
       fft(fb,0);
       for(int i=0;i<n;i++){
        fa[i]*=fb[i];
       }
       fft(fa,1); // IDFT
       for(int i=0;i<=2*N;i++){
        cout<<(ll)round(fa[i].real())<<' ';
       }
       cout<<'\n';
    }
    return 0;
}