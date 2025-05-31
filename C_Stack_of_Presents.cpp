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
       vector<ll> a(n),b(m),pos(n);
       for(ll i=0;i<n;i++){
        cin>>a[i];
        a[i]--;
        pos[a[i]]=i;
       }
       for(ll i=0;i<m;i++){
        cin>>b[i];
        b[i]--;
       }
       // base-case, pickup b[0]
       ll ans=2*pos[b[0]]+1;
       ll lst=pos[b[0]];
       for(ll i=1;i<m;i++){
        // Note: b[i-1] is not necessarily the present at the farthest index !
        // lst-> maxm of pos(b[j]) for 0<=j<i
        if(pos[b[i]]<lst){
            ans+=1;
        }
        else{
            ans+=2*(pos[b[i]]-i)+1;
            lst=max(lst,pos[b[i]]);
        }
       }
       cout<<ans<<"\n";
       
    }
    return 0;
}