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
       ll n,m;cin>>n>>m;
       if(m<n || m>=(n)*(n+1)/2){
        cout<<"-1\n";
        continue;
       }

       vector<bool> vis(n+1,0);
       ll r=n;
       while(m>=2*n){
        m-=r;
        vis[r]=1;
        r--;
       }
       ll head=n;
       if(r==n) head=1;
       ll p=m-(r-2);
       vis[p]=1;
       cout<<head<<"\n";
       for(int v=r;v<n;v++){
        cout<<r<<" "<<r+1<<"\n";
       }

       for(int v=2;v<=n;v++){
            if(!vis[v])cout<<"1 "<<v<<"\n";
        }
        cout<<"1 "<<p<<"\n";
        cout<<p<<" "<<r<<"\n";

    }
    return 0;
}