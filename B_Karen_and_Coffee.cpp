#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    const int MAX=2*1e5;
    int n,k,q;cin>>n>>k>>q;
    vector<int> c(MAX+2,0);
    for(int i=0;i<n;i++){
        int l,r;cin>>l>>r;
        c[r+1]--;
        c[l]++;
    }
    for(int i=1;i<=MAX;i++){
        c[i]+=c[i-1];
    }
    vector<int> cnt_pref(MAX+1,0);
    for(int i=1;i<=MAX;i++){
        cnt_pref[i]=cnt_pref[i-1];
        cnt_pref[i]+=c[i]>=k;
    }
    while(q--){
        int a,b;cin>>a>>b;
        int ans=cnt_pref[b]-cnt_pref[a-1];
        cout<<ans<<"\n";
    }
    return 0;
}