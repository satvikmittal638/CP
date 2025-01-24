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
       if(n==6){
        cout<<"1 1 2 3 1 2\n";
        continue;
       }
       vector<int> ans(n);
       for(int i=0;i<n-2;i++){
        ans[i]=i+1;
       }
       ans[n-2]=1;
        ans[n-1]=2;
       for(auto e:ans) cout<<e<<" ";
       cout<<"\n";
    }
    return 0;
}