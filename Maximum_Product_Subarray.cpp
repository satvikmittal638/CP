#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const int MAX=1e5+1;
int n;
vector<ll> a;

ll dp1[MAX],dp2[MAX];


int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       cin>>n;a.assign(n,0);
       for(auto &i:a) cin>>i;
       for(int i=0;i<MAX;i++){
        dp1[i]=LLONG_MIN;
        dp2[i]=LLONG_MAX;
       }
       dp1[0]=dp2[0]=a[0];
       for(int r=1;r<n;r++){
        dp1[r]=max({dp1[r-1]*a[r],dp2[r-1]*a[r],a[r]});
        dp2[r]=min({dp1[r-1]*a[r],dp2[r-1]*a[r],a[r]});
       }
       cout<<*max_element(dp1,dp1+n)<<'\n';



    }
    return 0;
}