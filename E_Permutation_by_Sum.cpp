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
       int n,l,r,s;cin>>n>>l>>r>>s;
       int z=r-l+1;
       int mn=z*(z+1)/2,mx=z*n-z*(z-1)/2;
       if(s<mn || s>mx){
        cout<<"-1\n";
        continue;
       }
       int del=s-mn;
       vector<int> ans;
       for(int i=z;i>=1;i--) ans.push_back(i);
       // now sprinkle this 'del' over the array
       int i=0;
       while(del){
        ans[i]++;
        del--;
        i=(i+1)%(ans.size());
       }
       vector<bool> used(n+1,0);
       for(auto e:ans) used[e]=1;
       int cnt=0;
       for(int i=1;i<=n && cnt<l-1;i++) if(!used[i]) {ans.insert(ans.begin(),i);used[i]=1;cnt++;}
       for(int i=1;i<=n;i++){
           if(!used[i]) ans.push_back(i);
        }
        for(auto e:ans) cout<<e<<" ";
       cout<<"\n";
    }
    return 0;
}