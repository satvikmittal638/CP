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
       multiset<int> ms;
       ms.insert({0,1,0,3,2,0,2,5});
       int i;
       for(i=0;i<n && ms.size();i++){
        auto it=ms.find(a[i]);
        if(it!=ms.end()){
            ms.erase(it);
        }
       }
       if(ms.size()) i=0;
       cout<<i<<"\n";
    }
    return 0;
}