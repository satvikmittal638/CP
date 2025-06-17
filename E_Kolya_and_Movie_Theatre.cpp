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
       ll n,m,d;cin>>n>>m>>d;
       vector<ll> a(n);for(auto &i:a) cin>>i;
       ll sum=0,ans=0;
       multiset<ll> st;
       for(int i=0;i<n;i++){
        ll cur=sum+a[i]-(i+1)*d;
        ans=max(ans,cur);
        if(a[i]>0){
            st.insert(a[i]);
            sum+=a[i];
            if(st.size()>=m){
                sum-=*(st.begin());
                st.erase(st.begin());
            }
        }
       }
       cout<<ans<<"\n";
    }
    return 0;
}