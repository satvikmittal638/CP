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
       vector<int> cowOfCard(n*m);
       for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int a;cin>>a;
            cowOfCard[a]=i;
        }
       }
        vector<vector<int>> seqn(n,vector<int>());
       for(int i=0,k=0;k<n*m && i<n;i++){
        int start=cowOfCard[k];
        seqn[i].push_back(start);
        k++;
        while(k<n*m && cowOfCard[k]!=start){
            seqn[i].push_back(cowOfCard[k]);
            k++;
        }
       }
       // check for equality of all sequences
       vector<int> ans=seqn[0];
       bool ok=1;
       for(int i=1;i<n && ok && seqn[i].size()>0;i++){

        if(ans.size()!=seqn[i].size()){
            ok=0;
        }

        for(int j=0;ok && j<ans.size();j++){
            if(ans[j]!=seqn[i][j]) {
                ok=0;
            }
        }
       }
       if(ok){
        for(auto e:ans) cout<<e<<" ";
       }
       else{
        cout<<"-1";
       }
       cout<<"\n";
    }
    return 0;
}