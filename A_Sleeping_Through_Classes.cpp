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
       string s;cin>>s;
       int cntWakeBuffer=0,ans=0;
       for(int i=0;i<n;i++){
        if(s[i]=='0'){
            if(cntWakeBuffer==0) ans++;
            else cntWakeBuffer--;
        }
        else{
            cntWakeBuffer=k;
        }
       }
       cout<<ans<<'\n';
    }
    return 0;
}