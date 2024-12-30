#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int n,q;cin>>n>>q;
    vector<int> a(n);for(auto &i:a) cin>>i;
    vector<int> freq(n,0);
    while(q--){
        int l,r;cin>>l>>r;l--;
        // difference array
        freq[l]++;
        if(r<n) freq[r]--;
    }
    int pref=0;
    for(int i=0;i<n;i++){
        pref+=freq[i];
        freq[i]=pref;
    }
    sort(rall(freq));
    sort(rall(a));
    ll ans=0ll;
    for(int i=0;i<n;i++){
        ans+=1ll*a[i]*freq[i];
    }
    cout<<ans<<"\n";
    return 0;
}