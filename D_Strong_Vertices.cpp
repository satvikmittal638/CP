#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       map<int,vector<int>> f;
       vector<int> a(n),b(n);
        for(auto &i:a) cin>>i;
        for(auto &i:b) cin>>i;
        for(int i=0;i<n;i++){
            f[a[i]-b[i]].emplace_back(i);
        }
        vector<int> ans=(*f.rbegin()).second; // the vertices with maxm value of a[i]-b[i]
        // sort(ans.begin(),ans.end());
        cout<<ans.size()<<"\n";
        for(auto e:ans) cout<<e+1<<" ";
        cout<<"\n";
    }
    return 0;
}