#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    // precompute fibonacci
    vector<int> fib(12);
    fib[0]=1;fib[1]=2;
    for(int i=2;i<=10;i++){
        fib[i]=fib[i-1]+fib[i-2];
    }
    int tt;cin>>tt;
    while(tt--){
       int n,m;cin>>n>>m;
       while(m--){
        int w,l,h;cin>>w>>l>>h;
        if(max({w,l,h})>=fib[n-1]+fib[n-2] && min({w,l,h})>=fib[n-1])cout<<"1";
        else cout<<"0";
       }
       cout<<"\n";
    }
    return 0;
}