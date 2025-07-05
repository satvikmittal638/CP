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
       vector<int> a(n),p_min(n,INT_MAX),s_max(n,INT_MIN);
       for(auto &i:a) cin>>i;
       p_min[0]=a[0];
       for(int i=1;i<n;i++){
        p_min[i]=min(p_min[i-1],a[i]);
       }
       s_max[n-1]=a[n-1];
       for(int i=n-2;i>=0;i--){
        s_max[i]=max(s_max[i+1],a[i]);
       }
       for(int i=0;i<n;i++){
        if(a[i]==p_min[i] || a[i]==s_max[i]) cout<<'1';
        else cout<<'0';
       }
       cout<<'\n';
    }
    return 0;
}