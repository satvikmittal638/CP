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
       string s;cin>>s;
       int n=s.length();
       // stores the minm length of the prefix with the required target prefix sum 
       vector<int> prefs(n+1,-1);//cnt_-cnt+->length of prefix
       prefs[0]=0;
       int cur=0;
       for(int i=0;i<n;i++){
        cur+=(s[i]=='-')-(s[i]=='+');
        if(prefs[cur]==-1){
            prefs[cur]=(i+1);
        }
       }
       ll ans=0ll+n;
       for(int init=0;init<n;init++){
        if(prefs[init+1]!=-1){
            ans+=(prefs[init+1]);
        }
        else{
            break;
        }
       }
       cout<<ans<<"\n";

    }
    return 0;
}