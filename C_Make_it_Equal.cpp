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
       multiset<int> s,t;
       for(int i=0;i<n;i++){
        int x;cin>>x;x%=k;
        s.insert(min(x,k-x));
       }
       for(int i=0;i<n;i++){
        int x;cin>>x;x%=k;
        t.insert(min(x,k-x));
       }
       cout<<(s==t?"YES":"NO")<<"\n";
       

    }
    return 0;
}