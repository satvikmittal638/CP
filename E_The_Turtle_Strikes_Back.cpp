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
       int n,m;cin>>n>>m;
       vector<vector<ll>> a(n,vector<ll>(m,0)),dp1(n,vector<ll>(m,LLONG_MIN)),dp2(n,vector<ll>(m,LLONG_MIN));
       for(auto &i:a){
        for(auto &j:i) cin>>j;
       }
       dp1[0][0]=a[0][0];
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0) continue;
            if(i==0) dp1[i][j]=dp1[i][j-1];
            else if(j==0) dp1[i][j]=dp1[i-1][j];
            else dp1[i][j]=max(dp1[i-1][j],dp1[i][j-1]);
            dp1[i][j]+=a[i][j];
        }
       }
        dp2[n-1][m-1]=a[n-1][m-1];
       for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(i==n-1 && j==m-1) continue;
            if(i==n-1) dp2[i][j]=dp2[i][j+1];
            else if(j==m-1) dp2[i][j]=dp2[i+1][j];
            else dp2[i][j]=max(dp2[i+1][j],dp2[i][j+1]);
            dp2[i][j]+=a[i][j];
        }
       }

       ll ans=LLONG_MAX;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ll ans1=dp1[i][j]+dp2[i][j]-3*a[i][j];
            ll ans2=dp1[i-1][j-1]
        }
       }
       cout<<ans<<'\n';

    }
    return 0;
}