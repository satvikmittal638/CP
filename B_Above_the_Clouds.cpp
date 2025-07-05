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
       string s;cin>>s;
       vector<int> cnt(26,0);
       for(auto e:s) cnt[e-'a']++;
       bool ok=0;
       for(int i=1;i<n-1;i++){
        if(cnt[s[i]-'a']>1){
            ok=1;break;
        }
       }
       cout<<(ok?"Yes":"No")<<"\n";
    }
    return 0;
}