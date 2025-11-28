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
       vector<int> a(n);for(auto &i:a) cin>>i;
       for(int i=1;i<n-1;i++){
        if(a[i]==-1) a[i]=0;
       }
       if(a[0]==-1 && a[n-1]==-1) a[0]=a[n-1]=0;
       if(a[0]==-1 && a[n-1]!=-1) a[0]=a[n-1];
       if(a[0]!=-1 && a[n-1]==-1) a[n-1]=a[0];
       cout<<abs(a[n-1]-a[0])<<'\n';
       for(auto e:a) cout<<e<<' ';
       cout<<'\n';
    }
    return 0;
}