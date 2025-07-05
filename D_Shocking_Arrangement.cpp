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
       vector<ll> pos,neg;
       ll mn=LLONG_MAX,mx=LLONG_MIN;
       for(int i=0;i<n;i++){
        ll x;cin>>x;
        mn=min(mn,x);
        mx=max(mx,x);
        if(x>=0) pos.push_back(x);
        else neg.push_back(x);
       }
       vector<ll> ans;
       ll sum=0ll;
       while(pos.size() || neg.size()){
        if(pos.size() && sum + pos.back() <= mx){
            ans.push_back(pos.back());
            sum += pos.back();
            pos.pop_back();
        }
        else if(neg.size() && sum + neg.back() > mn){ 
            ans.push_back(neg.back());
            sum += neg.back();
            neg.pop_back();
        }
        else break; // prevent infinite loop if neither condition is met
        }   
       if(mx==0 && mn==0){
        cout<<"No\n";
       }
       else{
        cout<<"Yes\n";
        for(auto e:ans) cout<<e<<" ";
        cout<<"\n";
       }
    }
    return 0;
}