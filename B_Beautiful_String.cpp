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
       string s;cin>>s;
       vector<int> ans;
       for(int i=0;i<n;i++){
        if(s[i]=='1'){
            ans.push_back(i+1);
        }
       }
    //    if(ans.size()==0)
       cout<<ans.size()<<'\n';
       for(auto e:ans) cout<<e<<' ';
       cout<<'\n';
    }
    return 0;
}