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
       string a,b;cin>>a>>b;
       vector<bool> c(n);
       for(int i=0;i<n;i++){
        c[i]=(a[i]!=b[i]);
       }
       // after the operation, all c[i]'s must be 0
       int i=0;
       while(i<n && c[i]==0) i++;
       while(1){
        // press i+1
        if(i<n-1){
            c[i]=!c[i];
            if(i<n-2) c[i+2]=!c[i+2];
        }
        // press n-2th button
        else{
            c[i]=!c[i];
            c[i-2]=!c[i-2];
        }
        
       }
       bool ok=1;
       for(int i=0;i<n;i++){
        ok&=(c[i]==0);
       }
       cout<<(ok?"YES":"NO")<<"\n";
    }
    return 0;
}