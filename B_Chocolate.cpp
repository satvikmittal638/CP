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
    vector<int> a(n);for(auto &i:a) cin>>i;
    if(count(all(a),1)==0){
        cout<<0;
        return 0;
    }
    ll ans=1ll;
    for(int i=0;i<n;){
        if(a[i]==1){
            i++;// skip the 1
            ll cnt=0ll;
            // count consective 0s
            while(i<n && a[i]==0){
                cnt++;
                i++;
            }
            // check if we have a closing 1
            if(i<n){
                ans*=cnt+1;
            }
        }
        else{
            i++;
        }
    }
    cout<<ans;
    return 0;
}