#include<bits/stdc++.h>
using namespace std;


int find(vector<int>& linker,vector<int>& sz,int a){
    while(a!=linker[a]){
        a=linker[a];
    }
    return a;
}

void unite(vector<int>& linker,vector<int>& sz,int a,int b){
    a=find(linker,sz,a);b=find(linker,sz,b);
    if(a!=b){
        if(sz[a]<sz[b]) swap(a,b);
        sz[a]+=sz[b];
        linker[b]=a;
    }
}

bool isSameSet(vector<int>& linker,vector<int>& sz,int a,int b){
    a=find(linker,sz,a);b=find(linker,sz,b);
    return a==b;
}



int main()
{
    int n,m;cin>>n>>m;
    vector<vector<int>> c_linkers(m+1,vector<int>(n+1,0));
    vector<vector<int>> c_szs(m+1,vector<int>(n+1,1));
    for(auto &color:c_linkers){
        for(int i=0;i<=n;i++){
            color[i]=i;
        }
    }
    for(int i=1;i<=m;i++){
        int a,b,c;cin>>a>>b>>c;
        unite(c_linkers[c],c_szs[c],a,b);
    }
    int q;cin>>q;
    while(q--){
        int u,v;cin>>u>>v;
        int cnt=0;
        for(int i=1;i<=m;i++){
            if(isSameSet(c_linkers[i],c_szs[i],u,v)){
                cnt++;
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}