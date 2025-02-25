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
       vector<int> a(n),b(n);
       for(auto &i:a) cin>>i;
       for(auto &i:b) cin>>i;
       int m;cin>>m;
       vector<int> d(m);
       map<int,int> mp_d;
       for(auto &i:d) {
        cin>>i;
        mp_d[i]++;
       }
       bool ok=find(all(b),d[m-1])!=b.end();
       for(int i=0;i<n;i++){
        // check if a multiset of elts of b where b[i]!=a[i]
        // is contained in d
        if(a[i]!=b[i]){
            ok&=mp_d[b[i]]>0;
            mp_d[b[i]]--;
        }
       }
       cout<<(ok?"YES":"NO")<<"\n";
    }
    return 0;
}