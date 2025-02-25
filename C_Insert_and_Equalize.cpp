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
       if(n==1){
        cout<<"1\n";
        continue;
       }
       sort(all(a));
       int x=0,k=-1;
       for(int i=1;i<n;i++){
        x=gcd(x,a[i]-a[i-1]);
       }
       for(int i=0;i<n;i++){
        if((a[n-1]-k*x)==a[i]){
            k--;
        }
       }
       ll ans=(1ll*n*a[n-1]-accumulate(all(a),0ll))/x -k;
       cout<<k<<"  ";
       cout<<ans<<"\n";


    }
    return 0;
}