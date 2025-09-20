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
       int n;cin>>n;
       vector<pair<int,int>> itvl;
       vector<int> L(n),R(n);
       for(int i=0;i<n;i++) {
        cin>>L[i]>>R[i];
        itvl.emplace_back(L[i],R[i]);
       }
       sort(all(L));sort(all(R));
       int ans=n-1;
       for(auto &[l,r]:itvl){
        int cur=0;
        auto it1=lower_bound(all(R),l);// points to first r[i]>=l
        cur+=it1-R.begin();
        auto it2=lower_bound(all(L),r+1);// points to first l[i]>r
        cur+=L.end()-it2;
        ans=min(ans,cur);
       }
       cout<<ans<<"\n";
    }
    return 0;
}