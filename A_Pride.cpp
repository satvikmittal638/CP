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
    vector<ll> a(n);for(auto &i:a) cin>>i;
    int cnt1=count(all(a),1ll);
    if(cnt1>0){
        cout<<(n-cnt1);
        return 0;
    }
    int minLen=INT_MAX;
    for(int l=0;l<n;l++){
        ll h=0ll;
        for(int r=l;r<n;r++){
            h=gcd(h,a[r]);
            if(h==1){
                minLen=min(minLen,r-l+1);
                break;
            }
        }
    }
    if(minLen==INT_MAX){
        cout<<"-1";
        return 0;
    }
    //minLen-1 opn to generate a 1, then use that 1 to make all others 1
    int ans=(minLen-1)+(n-1);
    cout<<ans;
    return 0;
}