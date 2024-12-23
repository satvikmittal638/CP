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
       string s;cin>>s;
       // count frequency of each letter in each prefix
       vector<vector<int>> pref_ctr(n,vector<int>(26,0));
       for(int i=0;i<n;i++){
        for(int j=0;j<26;j++){
            pref_ctr[i][j]+=(s[i]==('a'+j));
            if(i>0) pref_ctr[i][j]+=pref_ctr[i-1][j];
        }
       }
       vector<int> ans(26,0);
       for(int i=0;i<m;i++){
        int p;cin>>p;p--;
        for(int j=0;j<26;j++){
            ans[j]+=pref_ctr[p][j]; // press first p buttons
        }
       }
       // add final try
       for(int j=0;j<26;j++){
            ans[j]+=pref_ctr[n-1][j]; // press all button correctly
        }

       for(auto e:ans) cout<<e<<" ";
       cout<<"\n";
    }
    return 0;
}