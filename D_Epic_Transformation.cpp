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
       map<int,int> mp;
       for(int i=0;i<n;i++){
        int a;cin>>a;
        mp[a]++;
       }
       // make a pair of 2 numbers which have the maxm frequency
       // so as to maximize the variety available
       priority_queue<int> pq;
       for(auto &p:mp){
        pq.push(p.second);
       }
       while(pq.size()>1){
        int top1=pq.top();pq.pop();
        int top2=pq.top();pq.pop();
        top1--;
        top2--;
        if(top1) pq.push(top1);
        if(top2) pq.push(top2);
       }
       int ans=0;
       if(pq.size()==1) ans=pq.top();
       cout<<ans<<"\n";
    }
    return 0;
}