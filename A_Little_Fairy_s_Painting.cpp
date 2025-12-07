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
       set<int> a;
       for(int i=0;i<n;i++){
        int x;cin>>x;
        a.insert(x);
       }
       int c;
       for(int i=1;i<=1e3;i++){
        c=a.size();
        a.insert(c);
       }
       cout<<c<<'\n';

    }
    return 0;
}