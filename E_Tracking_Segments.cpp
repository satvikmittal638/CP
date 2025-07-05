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
       int n,m;cin>>n>>m;
       vector<int> l(m),r(m);
       for(int i=0;i<m;i++) {
        cin>>l[i]>>r[i];
        l[i]--;r[i]--;
       }
       int q;cin>>q;
       vector<int> query(q);
       for(auto &i:query) {
        cin>>i;
        i--;
       }

       // checks if the segment are beautiful after 1...k prefix of queries array
       // k is 1-indexed
       auto isGood=[&](int k){
        vector<int> a(n,0), pref(n,0);
        for(int i=0;i<k;i++){
            a[query[i]]=1;
        }
        pref[0]=a[0];
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+a[i];
        }

        bool isGood=0;
        for(int i=0;i<m;i++){
            isGood|=(pref[r[i]]-((l[i]>0)?pref[l[i]-1]:0))>(r[i]-l[i]+1)/2;
        }
        return isGood;
       };

       // BS on optimal k
       int lo=1,hi=q+1;
       while(lo<hi){
        int mid=(lo+hi)/2;
        if(isGood(mid)){
            hi=mid;
        }
        else{
            lo=mid+1;
        }
       }
       if(lo>q) lo=-1;
       cout<<lo<<"\n";
    //    cout<<isGood(4);
    }
    return 0;
}