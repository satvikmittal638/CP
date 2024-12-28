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
       vector<int> ctr(n+1,0);
       for(int i=0;i<n;i++){
        int a;cin>>a;
        ctr[a]++;
       }
       sort(rall(ctr));
       ll ans=0ll;
       int seeFor=n;
       for(int i=0;i<=n;i++){
        while(ctr[i]<seeFor) seeFor--;
        if(seeFor>0){
            ans+=seeFor;
            seeFor--;
        }
        else break;
        
       }
       cout<<ans<<"\n";
    }
    return 0;
}