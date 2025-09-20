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
       string s;cin>>s;
       bool ok=1;
       for(int i=0;i<n;i++){
        int len=0;
        while(i<n && s[i]=='1'){
            len++;
            i++;
        }
        if(len>=k){
            ok=0;
            break;
        }
       }
       if(ok){
        vector<int> ans(n);
        int x=1;
        // put smallest numbers at 1
        for(int i=0;i<n;i++){
            if(s[i]=='1') ans[i]=x++;
        }
        for(int i=0;i<n;i++){
            if(s[i]=='0') ans[i]=x++;
        }
        cout<<"YES\n";
        for(auto e:ans) cout<<e<<" ";
       }
       else{
        cout<<"NO";
       }
       cout<<"\n";
    }
    return 0;
}