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
       int n,k;cin>>n>>k;
       vector<int> a(n);for(auto &i:a) cin>>i;
       // O(n)
       auto check=[&](int x){
        vector<bool> seen(x, 0);
        int cnt = 0;
        int pieces=0;
        for(int i=0;i<n;i++){
            if(a[i]<x && !seen[a[i]]){
                seen[a[i]] = 1;
                cnt++;
            }
            if(cnt == x){
                pieces++;
                fill(seen.begin(), seen.end(), 0);
                cnt = 0;
            }
        }
        return pieces>=k;
       };
       int lo=0, hi=0,ans=0;
       // find mex of array(upper bound for the ans)
       set<int> tmp;
       for(int i=0;i<n;i++){
        tmp.insert(a[i]);
       }
       for(auto e:tmp){
        hi+=(e==hi);
       }

       while(lo<=hi){
           int mid=lo+(hi-lo)/2;
           if(check(mid)){
            ans=mid;
            lo=mid+1;
           }
           else{
            hi=mid-1;
           }
       }
       cout<<ans<<"\n ";
    }
    return 0;
}