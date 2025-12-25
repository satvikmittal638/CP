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

int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       // find a corner
       int mx=-1,corner=-1;
       for(int i=2;i<=n*n;i++){
        int d;
        cout<<"? 1 "<<i<<endl;cin>>d;
        if(d>mx){
            mx=d;
            corner=i;
        }
       }

       // now get all distances from this corner
       vector<int> dist1(n*n+1,0),dist2(n*n+1,0);
       int cand=-1,corner2=-1;
       mx=-1;
       for(int i=1;i<=n*n;i++){
        int d;
        cout<<"? "<<corner<<" "<<i<<endl;cin>>d;
        dist1[i]=d;
        // candidate for non-opposite corner
        if(d==n-1){
            if(cand==-1) cand=i;
            else{
                int z;
                cout<<"? "<<cand<<" "<<i<<endl;cin>>z;
                if(z>mx){
                    mx=z;
                    corner2=i;
                }
            }
        }
       }
       // now get all distances from 2nd corner
       for(int i=1;i<=n*n;i++){
        int d;
        cout<<"? "<<corner2<<" "<<i<<endl;cin>>d;
        dist2[i]=d;
       }
       vector<vector<int>> ans(n,vector<int>(n,0));
       //now compute coordinates (r,c) of each cell
       for(int i=1;i<=n*n;i++){
        int c=(dist1[i]+dist2[i]+3-n)/2,r=(dist1[i]-dist2[i]+n+1)/2;
        ans[r-1][c-1]=i;// 0-indexed
       }
       cout<<"!\n";
       for(auto x:ans){
           for(auto e:x) cout<<e<<' ';
           cout<<'\n';
       }
       cout<<endl;
    }
    return 0;
}