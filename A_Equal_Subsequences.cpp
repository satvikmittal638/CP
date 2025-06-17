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
       string s;
       for(int i=1;i<=k;i++) s.push_back('1');
       for(int i=k+1;i<=n;i++) s.push_back('0');
       cout<<s<<"\n";
    }
    return 0;
}