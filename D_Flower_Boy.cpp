#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int INF=1e9+5;
    int tt;cin>>tt;
    while(tt--){
       int n,m;cin>>n>>m;
       vector<int> a(n),b(m);
       for(auto &i:a) cin>>i;
       for(auto &i:b) cin>>i;
       vector<int> p(m,INF),s(m,-1);
       // build p
       int i=0,j=0;
       while(i<n && j<m){
        // pick this flower
        if(a[i]>=b[j]){
            p[j]=i;
            j++;
        }
        i++;
       }
       // build s
       i=n-1;j=m-1;
       while(i>=0 && j>=0){
        // pick this flower
        if(a[i]>=b[j]){
            s[j]=i;
            j--;
        }
        i--;
       }
       // no operation needed
       if(p[m-1]<n) {
        cout<<"0\n";
        continue;
       }
       int ans=INF;
       // edge cases
       if(s[1]>=0) ans=min(ans,b[0]);
       if(p[m-2]<=n) ans=min(ans,b[m-1]);
       for(int i=1;i<m-1;i++){
        // b[i] can be deleted
        if(p[i-1]<s[i+1]) ans=min(ans,b[i]);
       }
       if(ans>=INF) ans=-1;
       cout<<ans<<"\n";
    }
    return 0;
}