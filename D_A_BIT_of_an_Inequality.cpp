#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const int W=30;
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


template <typename T> vector<T> create(size_t n, T val) { return vector<T>(n, val); }
template <typename... Args> auto create(size_t n, Args... args) { return vector(n, create(args...)); }

int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<int> a(n+1,0),pxor(n+1,0),sxor(n+2,0);
       for(int i=1;i<=n;i++) cin>>a[i];

       for(int i=1; i<=n; i++) pxor[i] = pxor[i-1] ^ a[i];

       for(int i=n; i>=1; i--) sxor[i] = sxor[i+1] ^ a[i];

       // empty prefixes and suffixes are also included
       // let cntp[0][i][j] denote no. of prefixes s.t. the prefix xor of [1,k] s.t. 0<=k<=j has 0 at bit posn i
       // let cntp[1][i][j] denote no. of prefixes s.t. the prefix xor of [1,k] s.t. 0<=k<=j has 1 at bit posn i
       // let cnts[0][i][j] denote no. of suffixes s.t. the suffix xor of [k,n] s.t. j<=k<=n+1 has 0 at bit posn i
       // let cnts[1][i][j] denote no. of suffixes s.t. the suffix xor of [k,n] s.t. j<=k<=n+1 has 1 at bit posn i
       auto cntp=create(2,W,n+2,0), cnts=create(2,W,n+2,0);
       // build cntp
       for(int i=0;i<W;i++){
        for(int j=0;j<=n;j++){
            int bit=(pxor[j]&(1<<i))!=0;
            if(j>0) {
                cntp[0][i][j]=cntp[0][i][j-1];
                cntp[1][i][j]=cntp[1][i][j-1];
            }
            cntp[bit][i][j]++;
        }
       }

       // build cnts
       for(int i=0;i<W;i++){
        for(int j=n+1;j>=0;j--){
            bool bit=(sxor[j]&(1<<i))!=0;
            if(j<=n) {
                cnts[0][i][j]=cnts[0][i][j+1];
                cnts[1][i][j]=cnts[1][i][j+1];
            }
            cnts[bit][i][j]++;
        }
       }
       int totSum=pxor[n];

       ll ans=0ll;
       // now fix a y, and get all possible pairs (x,z), 1<=x<=y<=z<=n
       for(int y=1;y<=n;y++){
        int msbPos=bit_width((unsigned int)a[y])-1;
        // at msbPos, f(x,z) must have a 0 bit
        bool bit=(totSum&(1<<msbPos))!=0;
        // if totSum has 1 at msbPos, and we need subarray [x,z] that has 0 at msbPos, 
        // means [1,x-1]=0 and [z+1,n]=1 or [1,x-1]=1 and [z+1,n]=0
        if(bit){
            ans+=1ll*cntp[0][msbPos][y-1]*cnts[1][msbPos][y+1] + 1ll*cntp[1][msbPos][y-1]*cnts[0][msbPos][y+1];
        }
        // if totSum has 0
        // means [1,x-1]=[z+1,n]=0 or [1,x-1]=[z+1,n]=1
        else{
            ans+=1ll*cntp[0][msbPos][y-1]*cnts[0][msbPos][y+1] + 1ll*cntp[1][msbPos][y-1]*cnts[1][msbPos][y+1];
        }
       }
       cout<<ans<<'\n';



    }
    return 0;
}