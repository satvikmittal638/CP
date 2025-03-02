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
       vector<int> a(n),b(n);
       for(auto &i:a) cin>>i;
       for(auto &i:b) cin>>i;
       int cnt0=count(all(b),0),cnt1=count(all(b),1);
       if((cnt0!=0 && cnt1!=0) || is_sorted(all(a))){
        cout<<"Yes\n";
       }
       else{
        cout<<"No\n";
       }
    }
    return 0;
}