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
       map<int,int> cnt;
       vector<int> a(n);for(auto &i:a) {cin>>i;cnt[i]++;}
       sort(all(a));
       bool ok=1;
       for(int i=1;i<n-1;i+=2){
        if(a[i]!=a[i+1]) ok=0;
       }
       cout<<(ok?"YES":"NO")<<'\n';
    }
    return 0;
}