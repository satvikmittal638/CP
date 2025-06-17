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
       vector<int> a(m);for(auto &i:a) cin>>i;
       sort(all(a));
       if(n==1){
        cout<<a[0]<<" "<<a[m-1]<<" "<<a[0]<<" "<<a[m-1]<<" "<<a[0]<<" "<<a[m-1]<<"\n";
        continue;
       }
       vector<pair<int,int>> sched; // store the class rooms of {1st period,2nd period} for a group(ranging from 0 to n-1)
       int l=0,r=m-1;
       while(l<=r && sched.size()<n){
        sched.push_back({a[l],a[r]});
        if(sched.size()<n) sched.push_back({a[r],a[l]});
        // now minm and maxm rooms are both occupied in the 1st and 2nd period
        l++;
        r--;
       }
       // now rooms for 1st,3rd,5th period are same room for a group
       // rooms for 2nd,4th,6th are same room for a group
       for(auto [first,second]:sched){
        cout<<first<<" "<<second<<" "<<first<<" "<<second<<" "<<first<<" "<<second<<"\n";
       }
    }
    return 0;
}