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
       vector<int> p(n);for(auto &i:p) cin>>i;
       int i=1;
       // increasing part
       while(i<n && p[i-1]<p[i]) i++;
    //    cout<<i<<' ';
       // decreasing part
       while(i<n-1 && p[i]>p[i+1]) i++;
    //    cout<<i<<'\n';
       cout<<(i>=n-1?"YES":"NO")<<'\n';
    }
    return 0;
}