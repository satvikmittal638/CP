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
       vector<int> a(n+1),nrst(n+1);
       for(int i=1;i<=n;i++) cin>>a[i];
       nrst[1]=2;
       nrst[n]=n-1;
       for(int i=2;i<n;i++){
        if(a[i]-a[i-1]<a[i+1]-a[i]){
            nrst[i]=i-1;
        }
        else{
            nrst[i]=i+1;
        }
       }
       
       vector<int> f_p(n+1,0); // f_p[i] denotes cost to reach city i from city 1
       for(int i=2;i<=n;i++){
        f_p[i]=f_p[i-1];// reach (i-1)th city first
        if(nrst[i-1]==i) f_p[i]+=1;
        else f_p[i]+=(a[i]-a[i-1]);
       }

       vector<int> b_s(n+2,0); // b_s[i] denotes cost to reach city i from city n
       for(int i=n-1;i>=1;i--){
        b_s[i]=b_s[i+1]; // reach i+1th city first
        if(nrst[i+1]==i) b_s[i]+=1;
        else b_s[i]+=a[i+1]-a[i];
       }

       int m;cin>>m;
       while(m--){
        int x,y;cin>>x>>y;
        if(x<y){
            cout<<(f_p[y]-f_p[x]);
        }
        else{
            cout<<(b_s[y]-b_s[x]);
        }
        cout<<"\n";
       }
    //    for(int i=1;i<=n;i++) cout<<nrst[i]<<" ";
    //    cout<<"\n";
    //    for(int i=1;i<=n;i++) cout<<b_s[i]<<" ";
    }
    return 0;
}