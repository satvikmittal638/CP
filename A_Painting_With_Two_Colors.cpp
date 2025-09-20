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
       int n,a,b;cin>>n>>a>>b;
       if((n-b)%2==0){
        if(a<=b || (a>b && (n-a)%2==0)){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
       }
       else{
        cout<<"NO\n";
       }
    }
    return 0;
}