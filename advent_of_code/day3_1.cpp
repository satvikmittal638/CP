#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    ll ans=0ll;
    string s;
    while (cin >> s)
    {
        int n=s.length();
       vector<int> suf_mx(n,0);
       suf_mx[n-1]=s[n-1]-'0';
       for(int i=n-2;i>=0;i--){
        suf_mx[i]=max(suf_mx[i+1],s[i]-'0');
       }
       int cur=s[n-1]-'0';
       for(int i=0;i<n-1;i++){
        cur=max(cur,(s[i]-'0')*10+suf_mx[i+1]);
       }
       ans+=cur;
    }
    cout<<ans;
    return 0;
}