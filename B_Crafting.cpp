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
       vector<int> a(n),b(n);
       for(auto &i:a) cin>>i;
       for(auto &i:b) cin>>i;
       vector<int> c(n);
       int cntNeg=0;
       for(int i=0;i<n;i++){
        c[i]=a[i]-b[i];
        if(c[i]<0) cntNeg++;
       }
       if(cntNeg>1) {
        cout<<"NO\n";
        continue;
       }
       else if(cntNeg==0){
        cout<<"YES\n";
        continue;
       }
       int neg,mn=INT_MAX;
      for(int i=0;i<n;i++){
        if(c[i]<0) neg=c[i];
        else mn=min(mn,c[i]); // minm of non-negatives
      }
    //   cout<<neg<<" "<<mn;
      if(mn>=abs(neg)) cout<<"YES\n";
      else cout<<"NO\n";
       
    }
    return 0;
}