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
       bool ok=1;
       for(int i=0;i<n;i++){
        if(a[i]==0){
            if(i>0) ok&=a[i-1]==1;
            if(i<n-1) ok&=a[i+1]==1;
        }
       }
       ok&=(count(all(a),1)!=n);
       cout<<(ok?"NO":"YES")<<"\n";
    }
    return 0;
}