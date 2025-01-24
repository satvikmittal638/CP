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
       // maxheap
       priority_queue<pair<int,int>> pq;//{a[i],i}
       for(int i=0;i<n;i++){
        int a;cin>>a;
        if(a>0)pq.push({a,i});
       }
       vector<pair<int,int>> ans;
        while(pq.size()>1){
            auto [top1,i1]=pq.top();pq.pop();
            auto [top2,i2]=pq.top();pq.pop();
            ans.push_back({i1,i2});
            top1--;top2--;
            if(top1>0)
            pq.push({top1,i1});
            if(top2>0)
            pq.push({top2,i2});
        }
        cout<<ans.size()<<"\n";
        for(auto [i,j]:ans){
            cout<<i+1<<" "<<j+1<<"\n";
        }

    }
    return 0;
}