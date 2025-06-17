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
       vector<vector<int>> a(n,vector<int>(m));
       vector<int> sum(n,0);
       int tot=0;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) {
            cin>>a[i][j];
            sum[i]+=a[i][j];
        }
        tot+=sum[i];
       }
       if(tot%n!=0){
        cout<<"-1\n";
        continue;
       }
       tot/=n;
       // now traverse column wise
       vector<int> less,more;
       less.reserve(n);more.reserve(n);
       vector<tuple<int,int,int>> ans;
       for(int j=0;j<m;j++){
        for(int i=0;i<n;i++){
            if(sum[i]<tot && a[i][j]==0) less.push_back(i);
            if(sum[i]>tot && a[i][j]==1) more.push_back(i);
        }
        // now give 1s from more to less(in the j-th column only)
        for(int k=0;k<min(less.size(),more.size());k++){
            ans.emplace_back(more[k],less[k],j);
            sum[more[k]]--;sum[less[k]]++;
        }
        more.clear();less.clear(); // reset for next column
       }
       cout<<ans.size()<<"\n";
       for(auto [i,j,k]:ans) cout<<i+1<<" "<<j+1<<" "<<k+1<<"\n";
    }
    return 0;
}