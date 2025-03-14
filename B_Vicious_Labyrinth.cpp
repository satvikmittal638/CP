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
       int n,k;cin>>n>>k;
       vector<int> ans;
       if(k%2==0){
        for(int i=1;i<=n-2;i++){
            ans.push_back(n-1);
        }
        ans.push_back(n);
        ans.push_back(n-1);
       }
       else{
        for(int i=1;i<=n-1;i++){
            ans.push_back(n);
        }
        ans.push_back(n-1);
       }
       for(auto e:ans) cout<<e<<" ";
       cout<<"\n";
    }
    return 0;
}