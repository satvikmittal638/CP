#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()


int solve(int root, vector<pair<int,int>>& c,string &s){
    // leaf node
    if(c[root].first==-1 && c[root].second==-1){
        return 0;
    }
    int ans1=INT_MAX,ans2=INT_MAX;
    if(c[root].first!=-1){
        ans1=(s[root]!='L')+solve(c[root].first,c,s);
    }
    if(c[root].second!=-1){
        ans2=(s[root]!='R')+solve(c[root].second,c,s);
    }
    return min(ans1,ans2);
}

int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       string s;cin>>s;
       vector<pair<int,int>> c(n);
       for(int i=0;i<n;i++){
        int l,r;cin>>l>>r;
        l--;r--;
        c[i].first=l;
        c[i].second=r;
       }
       cout<<solve(0,c,s)<<"\n";
    }
    return 0;
}