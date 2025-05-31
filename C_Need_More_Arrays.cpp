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
       int n;cin>>n;
       vector<int> a(n);for(auto &i:a) cin>>i;
       vector<bool> isPrsnt(n,1);
       int last=a[0];
       for(int i=1;i<n;i++){
        if((a[i]-last)<=1){
            isPrsnt[i]=0; // drop the elt
        }
        else{
            last=a[i];
        }
       }
       int ans=accumulate(all(isPrsnt),0);
       cout<<ans<<"\n";
    }
    return 0;
}