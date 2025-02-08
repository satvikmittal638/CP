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
       /*
       Its guaranteed that grps k and n+m-2-k have same cardinality
       contents of all cells in group k must be equal amongst themselves(all 1 or 0)
       also for palindromicity , contents of group k must be equal to contents of grp n+m-2-k
       */
       vector<int> cnt0(n+m,0),cnt1(n+m,0);
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int a;cin>>a;
            cnt0[i+j]+=a==0;
            cnt1[i+j]+=a==1;
        }
       }
       int ans=0;
       for(int d1=n+m-2,d2=0;d2<d1;d1--,d2++){
        ans += min(cnt0[d1]+cnt0[d2],cnt1[d1]+cnt1[d2]);
       }
       cout<<ans<<"\n";
    }
    return 0;
}