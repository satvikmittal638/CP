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
       int a,b,c,d;cin>>a>>b>>c>>d;
       int x1=min(a,c),x2=min(b,d);
       if(x1<x2){
        cout<<"Flower";
       }
       else if(x1>x2){
        cout<<"Gellyfish";
       }
       else{
        cout<<"Gellyfish";
       }
       cout<<"\n";
    }
    return 0;
}