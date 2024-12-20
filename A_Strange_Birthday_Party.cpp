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
       int n,m;cin>>n>>m;
       vector<int> k(n),c(m);
       for(auto &i:k) cin>>i;
       for(auto &i:c) cin>>i;
       // sort in descending based on money each friend can take
       sort(rall(k),[&](int i,int j){
        return c[k[i]]<c[k[j]];
       });
       for(int i=0;i<n;i++){
        
       }
    }
    return 0;
}