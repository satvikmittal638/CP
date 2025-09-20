#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n,q;cin>>n>>q;
       vector<ll> a(n+1),p_sum(n+1,0ll),p_xor(n+1,0ll);
       for(int i=1;i<=n;i++) {
        cin>>a[i];
        p_sum[i]=p_sum[i-1]+a[i];
        p_xor[i]=p_xor[i-1]^a[i];
       }
       auto f=[&](int l,int r){
        return (p_sum[r]-p_sum[l-1])-(p_xor[r]^p_xor[l-1]);
       };
       int L,R;cin>>L>>R;

       int lans=1,rans=n;
       ll tgt=f(1,n);
       for(int r=1;r<=n;r++){
        int lo = 1, hi = r, l = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            ll val = f(mid, r);
            if (val == tgt) {
                l = mid;
                lo = mid + 1; // try to maximize l if possible
            } else if (val < tgt) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        if(l!=-1 && (rans-lans+1)>(r-l+1)){
            rans=r;
            lans=l;
        }
       }
       
       cout<<lans<<" "<<rans<<"\n";
    }
    return 0;
}