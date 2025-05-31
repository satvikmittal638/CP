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
       vector<pair<int,int>> t(n);
       for(int i=0;i<n;i++) cin>>t[i].first;
       for(int i=0;i<n;i++) cin>>t[i].second;
       // sort in descending first by decreasing a[i], then by increasing b[i]
       sort(rall(t),[](auto p1,auto p2){
        if(p1.first!=p2.first) return p1.first<p2.first;
        return p1.second>p2.second;
       });
       t.insert(t.end(),{0,0});
       
    //    for(int i=0;i<n;i++) cout<<t[i].first<<" "<<t[i].second<<"\n";
    //    cout<<"\n";

       // call all products for delivery by default
       int ans=t[0].first, self=0;
       for(int i=0;i<n;i++){
           // try to take the current product for self delivery
        int newAns=max(t[i+1].first,self+t[i].second);
        if(newAns<=ans){
            ans=newAns;
            self+=t[i].second;
        }
        else{
            break;
        }
        ans=min(newAns,ans);
       }
       cout<<ans<<"\n";
    }
    return 0;
}