#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int n,k;cin>>n>>k;
    string s,t,ans;cin>>s;
    for(int i=0;i<n;i++){
        t+=s[i];
        string cur;
        while(cur.size()<k){
            cur+=t;
        }
        while(cur.size()>k) cur.pop_back();
        if(ans=="") ans=cur;
        else ans=min(ans,cur);
    }
    cout<<ans;
    return 0;
}