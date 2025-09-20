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
       vector<int> cnt(101,0);
       for(int i=0;i<n;i++){
        int x;cin>>x;
        cnt[x]++;
       }
       bool ok=0;
       for(auto e:cnt){
        if(e>=2) ok=1;
       }
       cout<<(ok?"YES":"NO")<<"\n";
    }
    return 0;
}