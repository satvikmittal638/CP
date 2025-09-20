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
    vector<double> p(n);for(auto &i:p) cin>>i;
    sort(rall(p));
    if(p[0]==1){
        cout<<1;
        return 0;
    }
    double ans=0,sum=0,prod=1;
    // take a prefix of the ppl with maxm probability
    for(int i=0;i<n;i++){
        sum+=p[i]/(1-p[i]);
        prod*=1-p[i];
        ans=max(ans,sum*prod);
    }
    cout<<setprecision(10)<<ans;
    return 0;
}