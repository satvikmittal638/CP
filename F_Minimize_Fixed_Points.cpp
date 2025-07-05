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
       vector<int> p(n+1,0);
       for(int i=1;i<=n;i++) p[i]=i;
       for(int i=n;i>=1;i--){
        // find maxm factor of i
        int mxFact=-1;
        for(int j=2;j*j<=i;j++){
            if(i%j==0){
                mxFact=max(mxFact,max(j,i/j));
            }
        }
        if(mxFact!=-1){
            swap(p[i],p[mxFact]);
        }
       }
       for(int i=1;i<=n;i++) cout<<p[i]<<" ";
       cout<<"\n";
    }
    return 0;
}