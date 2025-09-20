#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    double a,b,c,d;cin>>a>>b>>c>>d;
    double ans=(a*d)/(b*d-(b-a)*(d-c));
    cout<<setprecision(7)<<ans;
    return 0;
}