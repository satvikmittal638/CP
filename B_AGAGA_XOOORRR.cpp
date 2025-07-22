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
       /*
       the array should be split into atmost 3 segments
       if it had even no. of equal elements, u can reduce the size to 2
       if it had odd, u can reduce it to size 3
       since remaining elements will have a xor of 0(equal elements xored even times=0)
       */
      // check for size=2
      int x1=0;
      for(int i=0;i<n;i++) x1^=a[i];
      if(x1==0){
        cout<<"YES\n";
        continue;
      }

      // check for size=3
      vector<int> pref_xor(n,0);
      pref_xor[0]=a[0];
      for(int i=1;i<n;i++) pref_xor[i]=pref_xor[i-1]^a[i];
      bool ok=0;
      for(int l=1;l<n && !ok;l++){
        for(int r=l;r<n;r++){
            if(pref_xor[l-1]==(pref_xor[r]^pref_xor[l-1]) && pref_xor[l-1]==(pref_xor[n-1]^pref_xor[r])){
                ok=1;
                break;
            }
        }
      }
      cout<<(ok?"YES":"NO")<<"\n";
    }
    return 0;
}