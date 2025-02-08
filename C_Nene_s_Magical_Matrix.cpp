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
       ll n;cin>>n;
       ll sum=n*(n+1)*(2*n+1)/3 - n*(n+1)/2;
       cout<<sum<<" "<<2*n<<"\n";
       for(int i=n;i>=1;i--){
        cout<<"1 "<<i<<" ";
        for(int j=1;j<=n;j++){
            cout<<j<<" ";
        }
        cout<<"\n";
        cout<<"2 "<<i<<" ";
        for(int j=1;j<=n;j++){
            cout<<j<<" ";
        }
        cout<<"\n";
       }
    }
    return 0;
}