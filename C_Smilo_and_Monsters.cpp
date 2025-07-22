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
       vector<ll> a(n);for(auto &i:a) cin>>i;
       sort(all(a));
       int i=0,j=n-1;
       ll x=0ll,ans=0ll;
       while(i<j){
        // use type-1 move
        if(x+a[i]<=a[j]){
            x+=a[i];
            ans+=a[i];
            i++;
        }
        else{
            ans+=a[j]-x;
            a[i]-=a[j]-x;
            // kill a[j] now by type-2 move
            ans++;
            a[j]=x=0ll;
            j--;
        }
       }
       // deal with i=j
       ll del=(a[j]-x)/2;
       //perform type 1 move till x<=a[j]
       x+=del;
       a[j]-=del;
       ans+=del;
       // perform type-2 move
       if(a[j]>1){
           a[j]-=x;
           ans++; 
       }
       ans+=a[j]>0; // perform type-1 move if anything left
       cout<<ans<<"\n";
    }
    return 0;
}