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
       vector<int> x(n),y(n);
       for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
       }
       int l=accumulate(all(x),0)+m-x[0];
       int b=accumulate(all(y),0)+m-y[0];
       cout<<2*(l+b)<<"\n";
    }
    return 0;
}