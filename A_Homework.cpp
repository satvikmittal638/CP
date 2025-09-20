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
       int n,m;
       string a,b,c;
       cin>>n>>a>>m>>b>>c;
       for(int i=0;i<m;i++){
        if(c[i]=='V'){
            a=b[i]+a;
        }
        else{
            a=a+b[i];
        }
       }
       cout<<a<<"\n";
    }
    return 0;
}