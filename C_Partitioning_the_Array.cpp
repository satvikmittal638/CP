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
       auto isPos = [&](int k) {
            int hcf = 0;
            for (int i = 0; i < n - k; i++) {
                hcf = gcd(hcf, abs(a[i] - a[i + k]));
            }
            return hcf != 1;
        };
    
       int ans=0; 
       for(int k=1;k*k<=n;k++){
        if(n%k==0){
            ans+=isPos(k);
            if(k*k!=n) ans+=isPos(n/k);
        }
       }
       cout<<ans<<"\n";
    }
    return 0;
}