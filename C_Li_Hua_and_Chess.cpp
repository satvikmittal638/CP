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
       int k,p,q;
       cout<<"? 1 1"<<endl;cin>>k;
       cout<<"? "<<k+1<<" 1"<<endl;cin>>p;
       cout<<"? 1 "<<k+1<<endl;cin>>q;
       if(p<=k) cout<<"! "<<p+1<<" "<<k+1;
       else cout<<"! "<<k+1<<" "<<q+1;
       cout<<endl;
    }
    return 0;
}