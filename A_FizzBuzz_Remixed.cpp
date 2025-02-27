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
       ll ans=(n / 15) * 3 + (n % 15 >= 0) + (n % 15 >= 1) + (n % 15 >= 2);

       cout<<ans<<"\n";
    }
    return 0;
}