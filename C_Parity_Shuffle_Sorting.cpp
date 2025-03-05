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
       vector<int> a(n);for(auto &i:a) cin>>i;
       if(n==1){
        cout<<"0\n";
        continue;
       }
       int tgtInd;
       if((a[0]+a[n-1])%2==0){
        tgtInd=n-1;
       }
       else{
        tgtInd=0;
       }
       vector<pair<int,int>> ans;
       ans.push_back({1,n});
       // now first and last elts are equal
       // do wih 1st elt
       for(int i=1;i<n-1;i++){
        if((a[tgtInd]+a[i])%2!=0){
            ans.push_back({1,i+1});
        }
       }
       // do with last elt
       for(int i=1;i<n-1;i++){
        if((a[tgtInd]+a[i])%2==0){
            ans.push_back({i+1,n});
        }
       }
       cout<<ans.size()<<"\n";
       for(auto &p:ans){
        cout<<p.first<<" "<<p.second<<"\n";
       }
       cout<<"\n";

    }
    return 0;
}