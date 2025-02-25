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
       vector<int> b(n-2);
       for(auto &i:b) cin>>i;
       bool ok=1;
       for(int i=1;i<n-3;i++){
        if(b[i]==0 && b[i-1]==1 && b[i+1]==1){
            ok=0;
            break;
        }
       }
       cout<<(ok?"YES":"NO")<<"\n";
    }
    return 0;
}