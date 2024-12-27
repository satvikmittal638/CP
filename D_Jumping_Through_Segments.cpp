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
       vector<pair<int,int>> seg(n);
       for(int i=0;i<n;i++){
        cin>>seg[i].first>>seg[i].second;
       }
       sort(all(seg));
       int ans=INT_MAX;
       for(int i=0;i<n-1;i++){
        ans=min(ans,seg[i+1].first-seg[i].second);
       }
       cout<<ans<<"\n";
    }
    return 0;
}