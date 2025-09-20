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
       int n,m;cin>>n>>m;
       vector<int> a(n),b(n);
       for(int i=0;i<n;i++) cin>>a[i]>>b[i];
       int ans=0;
       // start
       int dela = a[0];
       int delb = b[0]; // starting from side 0
       if(dela%2 == delb) ans += dela;
       else ans += dela-1;
    //    cout<<ans;
       for(int i=1;i<n;i++){
        int dela=a[i]-a[i-1],delb=abs(b[i]-b[i-1]);
        if(dela%2==delb){
            ans+=dela;
        }
        else{
            ans+=dela-1;
        }
       }
       // ending
       ans+=m-a[n-1];
       cout<<ans<<'\n';

    }
    return 0;
}