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
       vector<ll> b(2*n+1);
       set<ll> st;
       for(int i=1;i<=2*n;i++){
        cin>>b[i];
        st.insert(b[i]);
       }
       sort(all(b));

       ll altSum=0ll;
       for(int i=1;i<=n;i++){
        altSum-=b[i];
       }
       for(int i=n+1;i<=2*n;i++){
        altSum-=b[i];
       }
       b.insert(b.begin()+1,abs(altSum));
       for(int i=1;i<=2*n+1;i++) cout<<b[i]<<" ";
       cout<<"\n";

    }
    return 0;
}