#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const ll M=1e9;
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
        int n;cin>>n;
        vector<ll> x(n),y(n);
        for(int i=0;i<n;i++) cin>>x[i]>>y[i];
        ll mx=LLONG_MIN,mn=LLONG_MAX;
        for(int i=0;i<n;i++) {
            mx=max(mx,x[i]+y[i]);
            mn=min(mn,x[i]-y[i]);
        }
        ll z1,z2;
        cout<<"? R "<<M<<endl;
        cin>>z1;
        cout<<"? R "<<M<<endl;
        cin>>z1;
        cout<<"? U "<<M<<endl;
        cin>>z1;
        cout<<"? U "<<M<<endl;
        cin>>z1;

        cout<<"? L "<<M<<endl;
        cin>>z2;
        cout<<"? L "<<M<<endl;
        cin>>z2;
        cout<<"? L "<<M<<endl;
        cin>>z2;
        cout<<"? L "<<M<<endl;
        cin>>z2;

        ll sum=(z1+mx-4*M);
        ll dif=(z2-mn-4*M);
        ll a=(sum-dif)/2,b=(sum+dif)/2;
        cout<<"! "<<a<<" "<<b<<endl;
    }
    return 0;
}