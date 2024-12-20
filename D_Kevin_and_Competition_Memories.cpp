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
       vector<int> a(n),b(m);
       for(auto &i:a) cin>>i;
       for(auto &i:b) cin>>i;
       sort(all(b));
       vector<int> maxm_prob_solved(n);
       for(int i=0;i<n;i++){
        int ind=(upper_bound(all(b),a[i]))-b.begin();
        maxm_prob_solved[i]=ind;
       }
       int cnt_better_players=0;
       for(int i=1;i<n;i++){
        if(maxm_prob_solved[i]>maxm_prob_solved[0]) cnt_better_players++;
       }
       vector<int> ans(m,0);
       int j=maxm_prob_solved[0];
       for(int k=1;k<=m;k++){
        ans[k-1]=j/k + (m/k - j/k)*(cnt_better_players+1);
       }
       for(auto e:ans) cout<<e<<" ";
       cout<<"\n";
    }
    return 0;
}