#include<bits/stdc++.h>
using namespace std;
vector<int> linker,sz;

int find(int a){
    while(a!=linker[a]){
        a=linker[a];
    }
    return a;
}

void unite(int a,int b){
    a=find(a);b=find(b);
    if(a!=b){
        if(sz[a]<sz[b]) swap(a,b);
        sz[a]+=sz[b];
        linker[b]=a;
    }
}

bool isSameSet(int a,int b){
    a=find(a);b=find(b);
    return a==b;
}

int main()
{
    int n,m,k;cin>>n>>m>>k;
    linker.assign(n+1,0);sz.assign(n+1,1);
    for(int i=0;i<=n;i++) linker[i]=i;
    // this input is useless :) 
    while (m--)
    {
        int u,v;cin>>u>>v;
        // unite(u,v);
    }
    vector<string> query;
    vector<int> qu,qv;
    while(k--){
        string type;cin>>type;
        query.emplace_back(type);
        int u,v;cin>>u>>v;
        qu.emplace_back(u);qv.emplace_back(v);
    }
    // process the queries in reverse
    vector<string> ans;
    for(int i=query.size()-1;i>=0;i--){
        // add edge instead of cutting
        if(query[i]=="cut"){
            unite(qu[i],qv[i]);
        }else{
            if(isSameSet(qu[i],qv[i])){
                ans.emplace_back("YES\n");
            }else{
                ans.emplace_back("NO\n");
            }
        }
    }
    // print the ans to queries in original order
    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i];
    }

    
    return 0;
}