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
       int n,c;cin>>n>>c;
       vector<ll> a(n),pref(n),suf_mx(n);for(auto &i:a) cin>>i;
       a[0]+=c;// by default
       ll mxVote=a[0],mxInd=0;
       pref[0]=a[0];
       for(int i=1;i<n;i++) {
        pref[i]=pref[i-1]+a[i];
        if(a[i]>mxVote){
            mxVote=a[i];
            mxInd=i;
        }
       }
       suf_mx[n-1]=a[n-1];
       for(int i=n-2;i>=0;i--) suf_mx[i]=max(suf_mx[i+1],a[i]);
       vector<int> ans(n,-1);
       ans[mxInd]=0; // already winning person
       for(int i=0;i<n;i++){
        if(ans[i]==0) continue;
        ans[i]=i;// exlude all lower indices
        if(pref[i]<suf_mx[i]) ans[i]++;// remove additional winning person ahead of me
       }
       for(auto e:ans) cout<<e<<" ";
       cout<<"\n";
    }
    return 0;
}