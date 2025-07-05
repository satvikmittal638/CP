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
       ll n,l,r,k;cin>>n>>l>>r>>k;
       if(n%2!=0){
        cout<<l<<"\n";
       }
       else{
        // need 2 numbers now
        ll b = 1;
        while (b <= r) {
            if ((b & l) == 0 && b >= l) break;
            b <<= 1;
        }
        if (b > r || b==l || n==2) {
            cout << "-1\n";
            continue;
        }
        //now make last 2 numbers as b and others as l
        if(k<=n-2) cout<<l<<"\n";
        else cout<<b<<"\n";
       }
    }
    return 0;
}