#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

ll rf(ll a,ll b){
    return (a+b-1)/b;
}

int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
        ll n,b,c;cin>>n>>b>>c;
        if(b==0){
            if(c>=n) cout<<n;
            else if(c>=n-2) cout<<n-1;
            else cout<<-1;
        }
        else{
            if(c>=n) cout<<n;
            else cout<<n-rf(n-c,b);
        }
        cout<<"\n";
    }
    return 0;
}