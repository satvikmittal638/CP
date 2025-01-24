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
       int n,x;cin>>n>>x;
       vector<int> a(n);for(auto &i:a) cin>>i;
       int cntx=0;
       ll sum=0ll;
       for(int i=0;i<n;i++){
        cntx+=a[i]==x;
        sum+=a[i];
       }
       if(cntx==n) cout<<"0\n";
       else if(cntx>0 || sum==n*x) cout<<"1\n";
       else cout<<"2\n";
    }
    return 0;
}