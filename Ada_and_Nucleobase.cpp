#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
// FFT
using cd=complex<double>;
const double PI=acos(-1);
// computes bit reverse of 'num'
int reverse(int num,int logn){
    int res=0;
    for(int i=0;i<logn;i++){
        if(num&(1<<i)){
            res|=1<<(logn-1-i);
        }
    }
    return res;
}

void fft(vector<cd>& a, bool invert){
    int n=a.size();
    int logn=0;
    while((1<<logn)<n) logn++;
    // compute bit inversed version of a
    for(int i=0;i<n;i++){
        if(i<reverse(i,logn)){
            swap(a[i],a[reverse(i,logn)]);
        }
    }

    for(int len=2;len<=n;len<<=1){
        double ang=2*PI/len*(invert?-1:1);
        cd wlen(cos(ang),sin(ang));
        for(int i=0;i<n;i+=len){
            cd w(1);
            for(int j=0;j<len/2;j++){
                cd u=a[i+j],v=a[i+j+len/2]*w;
                a[i+j]=u+v;
                a[i+j+len/2]=u-v;
                w*=wlen;
            }
        }
    }
    if(invert){
        for(auto &x:a) x/=n;
    }
}

int main()
{
fastio;
    string s,r;cin>>s>>r;
    vector<char> mp={'A','C','T','G'};
    int n=1;
    while(n<s.size()+r.size()-1) n<<=1;
    vector<int> res(n,0);
    for(int j=0;j<4;j++){
        vector<cd> fs(n,0),fr(n,0);
        // build polynomial for s
        for(int i=0;i<s.size();i++){
            if(s[i]==mp[j]) fs[i]=1;
        }
        // build the polynomial for reversed(r)
        for(int i=0;i<r.size();i++){
            if(r[r.size()-1-i]==mp[j]) fr[i]=1;
        }
        fft(fs,0);
        fft(fr,0);
        for(int i=0;i<n;i++) fs[i]*=fr[i];
        fft(fs,1);
        for(int i=0;i<n;i++) res[i]+=round(fs[i].real());
    }
    int maxMatch=0;
    for(int i=0;i<=s.size()-r.size();i++){
        maxMatch=max(maxMatch,res[i+r.size()-1]);
    }
    cout<<r.size()-maxMatch;
    return 0;
}