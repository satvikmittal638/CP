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
       vector<int> a(5);
       cin>>a[0]>>a[1]>>a[3]>>a[4];
       int op1=a[0]+a[1],op2=a[3]-a[1],op3=a[4]-a[3];
       int ans=0;
       ans=1+max({(op1==op2)+(op1==op3),(op2==op1)+(op2==op3),(op3==op1)+(op3==op2)});
       cout<<ans<<"\n";
    }
    return 0;
}