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
       vector<int> p(n),s(n);
       for(auto &i:p) cin>>i;
       for(auto &i:s) cin>>i;
       int h1=p[n-1];
       bool ok=(h1==s[0]);
       for(int i=0;i<n;i++){
        if(gcd(p[i],s[i])!=h1){
            ok=0;
            break;
        }
       }
       cout<<(ok?"YES":"NO")<<"\n";
    }
    return 0;
}