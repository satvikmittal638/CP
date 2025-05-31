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
        int n,x;cin>>n>>x;
        vector<ll> a(n);for(auto &i:a) cin>>i;
        vector<ll> pref(n);
        pref[0]=a[0];
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+a[i];
        }
        // 0 for empty subarray
        vector<ll> ans(n+1,0ll);
        for(int l=1;l<=n;l++){
            //find maxm sub-array sum with given length
            ll mxSum=LLONG_MIN;
            for(int i=l-1;i<n;i++){
                mxSum=max(mxSum,pref[i]- (i>=l?pref[i-l]:0));
            }
            // update all answers from 0 to n
            for(int k=0;k<l;k++){
                ans[k]=max(ans[k],mxSum+k*x);
            }
            for(int k=l;k<=n;k++){
                ans[k]=max(ans[k],mxSum+l*x);
            }
        }
        for(auto e:ans) cout<<e<<" ";
        cout<<"\n";
    }
    return 0;
}