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
       int sum=accumulate(all(a),0);
       cout<<(sum==n*x?"YES":"NO")<<"\n";
    }
    return 0;
}