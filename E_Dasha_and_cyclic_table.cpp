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

vector<vector<cd>> transpose(vector<vector<cd>> &a){
    vector<vector<cd>> at(a[0].size(),vector<cd>(a.size()));
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[i].size();j++){
            at[j][i]=a[i][j];
        }
    }
    return at;
}

void fft2D(vector<vector<cd>>& a,bool invert){
    // apply FFT to all rows
    for(int i=0;i<a.size();i++){
        fft(a[i],invert);
    }
    a=transpose(a);
    // now apply FFT to all cols
    for(int i=0;i<a.size();i++){
        fft(a[i],invert);
    }
    a=transpose(a);
}

int main()
{
fastio;
    int n,m;cin>>n>>m;
    vector<string> a(n);
    for(auto &i:a) cin>>i;
    int r,c;cin>>r>>c;
    vector<string> p(r);for(auto &i:p) cin>>i;
    
    // resize to nearest power of 2
    int exp_r=r+n-1,exp_c=c+m-1;// maxm indices needed at corner
    int r1=1,c1=1;
    while(r1<exp_r+r-1)r1<<=1;
    while(c1<exp_c+c-1)c1<<=1;
    vector<vector<cd>> fa(r1,vector<cd>(c1,0)), fprev(r1,vector<cd>(c1,0));
   
    // 2-D poly for A
    for(int i=0;i<exp_r;i++){
        for(int j=0;j<exp_c;j++){
            double ang=(2*PI*(a[i%n][j%m]-'a'))/26;// cyclic wrap around
            fa[i][j]=cd(cos(ang),sin(ang));
        }
    }

    int cntWild=0;
    // 2-D poly for P
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(p[i][j]=='?'){
                cntWild++;
            }
            else{
                double ang=(2*PI*(p[i][j]-'a'))/26;
                if(p[i][j]!='?') fprev[r-1-i][c-1-j]=cd(cos(ang),-sin(ang)); // 0 for wildcard character
            }
        }
    }

    // find fft
    fft2D(fa,0);
    fft2D(fprev,0);

    //find convoln
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            fa[i][j]*=fprev[i][j];
        }
    }
    fft2D(fa,1);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            double val=fa[i+r-1][j+c-1].real(), need=r*c-cntWild;
            cout<<(abs(val-need)<1e-3);
        }
        cout<<'\n';
    }
    return 0;
}