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
       vector<int> ans(n+1,0);
       int ptr=1;
       for(int i=k;i<=n;i+=k){
        ans[i]=ptr;
        ptr++;
       }
       for(int i=1;i<=n;i++){
        if(ans[i]==0){
            ans[i]=ptr;
            ptr++;
        }
       }
       for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
       cout<<"\n";
    }
    return 0;
}