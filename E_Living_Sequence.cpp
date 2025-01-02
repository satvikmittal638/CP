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
       ll k;cin>>k;
       string base9;
       while(k){
        int d=k%9;
        if(d>3) d++;
        base9=to_string(d)+base9;
        k/=9;
       }
        cout<<base9<<"\n";
    }
    return 0;
}