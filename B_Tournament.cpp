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
       int n,j,k;cin>>n>>j>>k;
       j--;
       vector<int> a(n);
       for(auto &i:a) cin>>i;
       int mx=*max_element(all(a));
       if(a[j]==mx) cout<<"YES\n";
       else{
        if(k>=2) cout<<"YES\n";
        else cout<<"NO\n";
       }
    }
    return 0;
}