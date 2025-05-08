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
       vector<int> ans(n);
       int mx=n,mn=1;
       for(int i=n-2;i>=0;i--){
        if(s[i]=='<') {
            ans[i+1]=mn;
            mn++;
        }
        else{
            ans[i+1]=mx;
            mx--;
        }
       }
       ans[0]=mn; // mn=mx at this point
       for(auto e:ans) cout<<e<<" ";
       cout<<"\n";
    }
    return 0;
}