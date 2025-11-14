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
       ll n,x;cin>>n>>x;
       deque<ll> a(n);for(auto &i:a) cin>>i;
       sort(all(a));
       ll curS=0ll,bonus=0ll;
       vector<ll> ans;
       while(a.size()){
        ll back=a.back(),front=a.front();
        if(a.back()>=x-(curS%x)){
            ans.push_back(back);
            curS+=back;
            bonus+=back;
            a.pop_back();
        }
        else{
            ans.push_back(front);
            curS+=front;
            a.pop_front();
        }
       }
       cout<<bonus<<'\n';
       for(auto e:ans) cout<<e<<' ';
       cout<<'\n';

    }
    return 0;
}