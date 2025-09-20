#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int m,n;cin>>m>>n;
    double ans=0;
    for(double k=1;k<=m;k++){
        ans+=k*(pow(k/m,n)-pow((k-1)/m,n));
    }
    cout<<setprecision(5)<<ans;
    return 0;
}