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
       ll k,n,a,b;cin>>k>>n>>a>>b;
       if((k%n==0 && k/n <=b) || (k%n!=0 && k/n <b)){
        cout<<"-1\n";
        continue;
       }
       ll p;
       if((k-b*n)%(a-b)!=0){
        p=(k-b*n)/(a-b);
       }
       else{
        p=(k-b*n)/(a-b)-1;
       }
       p=min(p,n);
       cout<<p<<"\n";
    }
    return 0;
}