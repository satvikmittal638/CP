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
       int n;cin>>n;
       vector<int> a(n);for(auto &i:a) cin>>i;
       if(n==1) {
        cout<<a[0]<<"\n";
        continue;
       }
       sort(all(a));
       int x=a[n-1]+a[n-2]-1;
       for(int i=n-3;i>=0;i--){
        x=a[i]+x-1;
       }
       cout<<x<<"\n";
    }
    return 0;
}