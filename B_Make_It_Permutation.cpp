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
       cout<<2*n-3<<"\n";
       for(int i=2;i<=n;i++){
        cout<<i<<" 1 "<<i<<"\n";
       }
       for(int i=1;i<=n-2;i++){
        cout<<i<<" "<<i+1<<" "<<n<<"\n";
       }
    }
    return 0;
}