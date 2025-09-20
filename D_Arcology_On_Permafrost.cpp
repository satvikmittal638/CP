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
       int n,m,k;cin>>n>>m>>k;
       int x1=n-m*k,x2=n/(m+1);
       if(n<(m+1)*k){
        for(int i=0;i<n;i++){
            cout<<(i%k)<<" ";
        }
       }
       else{
        for(int i=0;i<n;i++){
            cout<<(i%x2)<<" ";
        }
       }
       cout<<"\n";
    }
    return 0;
}