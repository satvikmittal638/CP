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
       vector<string> a(n);for(auto &i:a) cin>>i;
       string s;
       for(int i=0;i<n;i++){
        s=min(s+a[i],a[i]+s);
       }
       cout<<s<<'\n';
    }
    return 0;
}