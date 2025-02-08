#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

void solve(int n,int k,vector<int>& ans){
    if(ans.size()==n) return;
    if(k<n){
        for(int i=1;i<=k-1 && ans.size()<n;i++){
            ans.push_back(-1);
        }
        if(k>0 && ans.size()<n) ans.push_back(200);
        if(ans.size()<n)ans.push_back(-400);
    }
    else{
        solve(n-1,k-n,ans);
        if(ans.size()<n) ans.push_back(1000);
    }
}

int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n,k;cin>>n>>k;
       vector<int> ans;
       solve(n,k,ans);
       for(auto e:ans)cout<<e<<" ";
       cout<<"\n";
    }
    return 0;
}