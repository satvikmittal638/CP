#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    ll tt;cin>>tt;
    while(tt--){
       ll n,m;cin>>n>>m;
       vector<ll> cnt(n+1,0); // count number of tasks ith worker is proficient in
       for(ll i=1;i<=m;i++){
        ll a;cin>>a;
        cnt[a]++;
       }
       // checks if all tasks can be completed in time t
       auto isSafe=[&](ll t){
        ll tasksLeft=m;
        for(ll i=1;i<=n;i++){
            ll myT=t;
            ll prof_tasks_done=min(t,cnt[i]);
            myT-=prof_tasks_done;
            ll nonProf_tasks_done=myT/2;
            tasksLeft-=(prof_tasks_done+nonProf_tasks_done);            
        }
        return tasksLeft<=0; // tasks<0 if multiple workers try to do overlapping tasks
       };
       ll lo=1,hi=2*m;
       while(lo<hi){
        ll mid=(lo+hi)/2;
        if(isSafe(mid)){
            hi=mid;
        }else{
            lo=mid+1;
        }
       }
       cout<<lo<<"\n";
    }
    return 0;
}