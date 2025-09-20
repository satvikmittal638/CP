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
       ll n,c,s1=0ll,s2=0ll,intn=0ll;cin>>n>>c;
       vector<int> mod0,mod1;
       for(int i=0;i<n;i++){
        ll x;cin>>x;
        s1+=x/2 +1;// no. of soln of x+y=s[i] for 0<=x<=y<=c
        s2+=c-x+1;// no. of soln of y-x=s[i] for 0<=x<=y<=c
        if(x%2) mod1.push_back(x);
        else mod0.push_back(x);
       }
       auto process=[&](vector<int> s){
        ll cnt=0ll;
        for(ll j=0;j<s.size();j++){
            int imax=upper_bound(s.begin()+j,s.end(),2*c-s[j])-s.begin()-1;
            // all elts in [j,imax] are suitable
            cnt+=(imax-j+1);
        }
        return cnt;
       };
       intn=process(mod0)+process(mod1);
       ll bad=s1+s2-intn;
       ll ans=(c+1)*(c+2)/2-bad;
       cout<<ans<<"\n";
    }
    return 0;
}