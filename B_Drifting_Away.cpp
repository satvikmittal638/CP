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
       int ans=0;
       for(int i=0;i<n-1;i++){
        if((s[i]=='*' && s[i+1]=='*') || (s[i]=='*' && s[i+1]=='<') || (s[i]=='>' && s[i+1]=='*') || (s[i]=='>' && s[i+1]=='<')){
            ans=-1;
            break;
        }
       }
       if(ans==-1){
        cout<<"-1\n";
        continue;
       }
       map<char,int> cnt;
       for(int i=0;i<n;i++){
        cnt[s[i]]++;
       }
       ans=max(cnt['<'],cnt['>'])+cnt['*'];
       cout<<ans<<'\n';

    }
    return 0;
}