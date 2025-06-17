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
       int n,k;cin>>n>>k;
       vector<int> a(n);
       for(int i=0;i<n;i++){
        cin>>a[i];
        a[i]=((a[i]<=k)?1:-1);
       }
       auto check1=[&](){
        vector<int> p(n),msp(n);
        p[0]=a[0];
        for(int i=1;i<n;i++) p[i]=p[i-1]+a[i];
        msp[n-2]=p[n-2];
        for(int i=n-3;i>=1;i--){
            msp[i]=max(msp[i+1],p[i]);
        }
        for(int i=0;i<n-2;i++){
            if(p[i]>=0 && msp[i+1]>=p[i]) return 1;
        }
        return 0;
       };
       int p=0,x=-1,y=-1;
       for(int i=0;i<n;i++){
        p+=a[i];
        if(p>=0) {
            x=i; 
            break;
        }
       }
       int s=0;
       for(int i=n-1;i>=0;i--){
        s+=a[i];
        if(s>=0) {
            y=i; 
            break;
        }
       }
       bool ok=0;
       if(x>=0 && y<n && (y-x)>=2) ok=1;
       if(check1()) ok=1;
       reverse(all(a));
       if(check1()) ok=1;
       cout<<(ok?"YES":"NO")<<'\n';
       

    }
    return 0;
}