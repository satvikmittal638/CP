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
       vector<int>a(n);for(auto &i:a) cin>>i;
       if((a[0]+a[n-1])%(n+1)==0 && (a[0]-a[n-1])%(n-1)==0){
        int p,q;
        p=(a[0]+a[n-1])/(n+1) - (a[0]-a[n-1])/(n-1);
        q=(a[0]+a[n-1])/(n+1) + (a[0]-a[n-1])/(n-1);
        if(p%2==0 && q%2==0 && p>=0 && q>=0){
            p/=2;
            q/=2;
            bool ok=1;
            for(int i=1;i<n-1;i++){
                if(a[i]!=(i+1)*p+(n-i)*q){
                    ok=0;
                    break;
                }
            }
            cout<<(ok?"YES":"NO")<<"\n";
        }
        else{
            cout<<"NO\n";
            continue;
        }
       }
       else{
        cout<<"NO\n";
        continue;
       }
           
    }
    return 0;
}