#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const int MAX=1e6;
int main()
{
fastio;
    int a,b,c,d;cin>>a>>b>>c>>d;
    vector<ll> p(MAX+1,0ll);
    for(int x=a;x<=b;x++){
        // add 1 to [x+b,x+c]
        p[x+b]++;
        p[x+c+1]--;
    }
    partial_sum(all(p),p.begin());// now p[s] is no. of (x,y) s.t. x+y=s subject to x E [a,b] and y E [b,c]
    for(int i=MAX-1;i>=0;i--){
        p[i]+=p[i+1];
    }
    // now p[s] is no. of (x,y) s.t. x+y>=s subject to given constraints
    ll ans=0ll;
    for(int z=c;z<=d;z++){
        ans+=p[z+1]; // no. of (x,y) s.t. x+y>z
    }
    cout<<ans;
    return 0;
}