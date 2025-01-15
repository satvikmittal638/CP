#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
#define MOD 1000000007


ll ceil(ll a, ll b){
    return (a+b-1)/b;
}

int main()
{
fastio;
    ll n,l,r;cin>>n>>l>>r;
    ll cnt0=0,cnt1=0,cnt2=0;
    if(ceil(l,3)<=r/3) cnt0=r/3-ceil(l,3)+1;
    if(ceil(l+2,3)<=(r+2)/3) cnt1=(r+2)/3-ceil(l+2,3)+1;
    if(ceil(l+1,3)<=(r+1)/3) cnt2=(r+1)/3-ceil(l+1,3)+1;

    // cout<<cnt0<<" "<<cnt1<<" "<<cnt2<<" ";
    ll prev0,prev1,prev2,cur0,cur1,cur2;
    cur0=prev0=cnt0;
    cur1=prev1=cnt1;
    cur2=prev2=cnt2;
    
    for(int i=1;i<n;i++){
        cur0=prev0*cnt0 + prev1*cnt2+prev2*cnt1;
        cur1=prev0*cnt1+prev1*cnt0+prev2*cnt2;
        cur2=prev0*cnt2+prev1*cnt1+prev2*cnt0;

        cur0%=MOD;
        cur1%=MOD;
        cur2%=MOD;

        prev0=cur0;
        prev1=cur1;
        prev2=cur2;
    }
    cout<<cur0;
    return 0;
}