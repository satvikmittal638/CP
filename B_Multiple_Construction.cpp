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
       vector<int> ans(2*n+1,0);
       int x=n;
       for(int i=1;i<=2*n;i++){
        if(ans[i]==0){
            ans[i]=x;
            // find a usable position
            for(int j=i+x;j<=2*n;j+=x){
                if(ans[j]==0) {ans[j]=x;x--;break;}
            }
        }
       }
       for(int i=1;i<=2*n;i++){
        cout<<ans[i]<<' ';
       }
       cout<<'\n';
    }
    return 0;
}