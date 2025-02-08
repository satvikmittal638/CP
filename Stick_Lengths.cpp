#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int n;cin>>n;
    vector<int> p(n);for(auto &i:p) cin>>i;
    sort(all(p));
    ll c1=0ll,c2=0ll;
    for(int i=0;i<n;i++){
        c1+=abs(p[i]-p[n/2]);
        c2+=abs(p[i]-p[(n+1)/2]);
    }
    cout<<min(c1,c2);
    return 0;
}