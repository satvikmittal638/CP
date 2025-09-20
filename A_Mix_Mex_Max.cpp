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
       vector<int> a(n);for(auto &i:a) cin>>i;
       // ans only for equal array !=0
       map<int,int> cnt;
       for(int i=0;i<n;i++){
        cnt[a[i]]++;
       }
       bool ok=1;
       if(cnt.size()-(cnt[-1]>0)<=1) ok=1;
       else ok=0;
       if(cnt[0]==n) ok=0;
       if(cnt[0]>0 && cnt[0]+cnt[-1]==n) ok=0;
       cout<<(ok?"YES":"NO")<<'\n';
    }
    return 0;
}