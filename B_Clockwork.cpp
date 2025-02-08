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
       bool ok=1;
       for(int i=1;i<=n;i++){
        int a;cin>>a;
        ok&=(a>2*max(i-1,n-i));
       }
       cout<<(ok?"YES":"NO")<<"\n";
    }
    return 0;
}