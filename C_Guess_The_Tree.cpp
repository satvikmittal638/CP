#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

void ask(int a,int b){
    cout<<"? "<<a<<" "<<b<<endl;
}

int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       set<pair<int,int>> edges;
       // discover (n-1) edges
       for(int v=2;v<=n;v++){
        int prev_res,cur_res;
        ask(v,1);
        cin>>prev_res;
        if(v==prev_res){
            edges.insert({1,v});
            continue;
        }
        ask(v,prev_res);
        cin>>cur_res;
        while(cur_res!=v){
            ask(v,cur_res);
            prev_res=cur_res;
            cin>>cur_res;
        }
        edges.insert({min(v,prev_res),max(v,prev_res)});
       }
       cout<<"! ";
       for(auto e:edges){
        cout<<e.first<<" "<<e.second<<" ";
       }
       cout<<endl;
    }
    return 0;
}