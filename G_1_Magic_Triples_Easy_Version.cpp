#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
const int MAX=1e6;
    vector<ll> cnt(MAX+1,0ll); // ! using a map will give TLE
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<int> a(n);
       for(auto &i:a) {
        cin>>i;
        cnt[i]++;
       }
       ll ans=0ll;
       // b=1
    //    for(auto f:cnt){
    //     ans+=f*(f-1)*(f-2);// fP3 ways
    //    }

       // b>=2;
       for(int i=0;i<n;i++){
        ans+=(cnt[a[i]]-1)*(cnt[a[i]]-2); // same as fP3=f(f-1)(f-2)=sum up (f-1)(f-2)  f times
            for(int b=2;a[i]*b*b<=MAX;b++){
            ans+=cnt[a[i]*b]*cnt[a[i]*b*b];
        }
       }
       cout<<ans<<"\n";
       // reset for reuse
       for(int i=0;i<n;i++) cnt[a[i]]=0ll;
    }
    return 0;
}