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
       vector<int> a(n);for(auto &i:a) cin>>i;
       set<pair<int,int>> toPaint;
       for(int i=0;i<n;i++){
        if(s[i]=='B') toPaint.insert({a[i],i});
       }
       string cur(n,'R');
       while(toPaint.size() && k){
        auto [val,pos]=*toPaint.rbegin();
        cur[pos]='B';
        // paint ngbrs if necessary in the same operation itself
        int i=pos-1,j=pos+1;
        while(j<n && cur[j]=='R' && s[j]=='B'){
            cur[j]='B';
            toPaint.erase({a[j],j});
            j++;
        }
        while(i>=0 && cur[i]=='R' && s[i]=='B'){
            cur[i]='B';
            toPaint.erase({a[i],i});
            i--;
        }
        k--;
       }
       int ans=0;
       for(int i=0;i<n;i++){
        if(cur[i]!=s[i]) ans=max(ans,a[i]);
       }
       cout<<ans<<"\n";
    }
    return 0;
}