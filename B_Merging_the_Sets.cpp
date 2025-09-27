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
       int n,m;cin>>n>>m;
       vector<vector<int>> s(n,vector<int>());
       vector<int> cnt(m+1,0);
       for(int i=0;i<n;i++){
        int l;cin>>l;
        s[i].assign(l,0);
        for(int j=0;j<l;j++){
            cin>>s[i][j];
            cnt[s[i][j]]++;
        }
       }
       bool ok=1;
       // select all sets
       for(int i=1;i<=m;i++){
        if(cnt[i]==0){
            ok=0;
            break;
        }
       }
       int cntRem=0;
       // remove 1 set
       for(int i=0;i<n;i++){
        bool canRem=1;
        for(auto e:s[i]){
            if(cnt[e]<2){
                canRem=0;
                break;
            }
        }
        cntRem+=canRem;
       }
       cout<<((cntRem>=2 && ok)?"YES":"NO")<<'\n';


    }
    return 0;
}