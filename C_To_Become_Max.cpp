#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const int INF=1e9;

// Worst case:O(n) due to bound on i
ll f(int i,int x,vector<int>& a){
    // can't increase the last element to x
    if(i==a.size()-1 && x>a[i]) return INF;
    
    if(i==a.size() || x<=a[i]) return 0;
    return (x-a[i])+f(i+1,x-1,a);
}

int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n,k;cin>>n>>k;
       vector<int> a(n);for(auto &i:a) cin>>i;
       auto isSafe=[&](int x){
        ll minOp=INF;
        for(int i=0;i<n;i++){
            minOp=min(minOp,f(i,x,a));
        }
        return minOp<=k;
       };
       int mx=*max_element(all(a));
       int lo=mx,hi=mx+n,ans=mx;
       while(lo<=hi){
        int mid=(lo+hi)/2;
        if(isSafe(mid)){
            ans=mid;
            lo=mid+1;
        }
        else{
            hi=mid-1;
        }
       }
       cout<<ans<<"\n";
    }
    return 0;
}