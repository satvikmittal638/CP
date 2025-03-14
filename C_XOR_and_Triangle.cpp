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
       int x;cin>>x;

       int y=x^(x&(-x));
       if((x+y<=(x^y))){
        cout<<"-1\n";
        continue;
       }
       cout<<y<<"\n";
    }
    return 0;
}