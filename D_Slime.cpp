#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;

    int n,cntNeg=0;cin>>n;
    ll ans=0ll;
    vector<ll> a(n);
    for(auto &i:a) {
    cin>>i;
    ans+=abs(i);
    cntNeg+=i<0;
    }
    // all elts were supplied with -ve sign->impossible situation
    // then supply +ve sign to maxm elt(least -ve elt)
    if(cntNeg==n){
    ans+=2*(*max_element(all(a)));
    }
    // all elts were given a +ve sign->impossible situation
    // supply a -ve sign to minm elt(least position)
    else if(cntNeg==0 && n>=2){
    ans-=2*(*min_element(all(a)));
    }
    cout<<ans;
       
    return 0;
}