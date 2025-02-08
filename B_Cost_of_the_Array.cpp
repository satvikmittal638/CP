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
       int n,k;cin>>n>>k;
       vector<int> a(n);for(auto &i:a) cin>>i;
       if(n==k){
        bool ok=0;
        int i;
        for(i=1;i<n;i+=2){
            if(a[i]!=(i+1)/2){
                cout<<(i+1)/2<<"\n";
                ok=1;
                break;
            }
        }
        if(!ok) cout<<(i+1)/2<<"\n";
        continue;
       }
       else{
        bool ok=0;
        for(int i=1;i<n-k+2;i++){
            if(a[i]!=1){
                cout<<1<<"\n";
                ok=1;
                break;
            }
        }
        if(!ok) cout<<2<<"\n";
       }
    }
    return 0;
}