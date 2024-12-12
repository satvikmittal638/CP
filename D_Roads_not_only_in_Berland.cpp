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
    int n;cin>>n;
    linker.assign(n+1,0);sz.assign(n+1,1);
    for(int i=0;i<=n;i++) linker[i]=i;
    vector<pair<int,int>> build,close;
    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        if(!isSameSet(a,b)){
            unite(a,b);
        }else{
            close.emplace_back(make_pair(a,b)); // don't make unneccessary road
        }
    }

    for(int i=2;i<=n;i++){
        // connect 2 disconnected vertices
        if(!isSameSet(1,i)){
            unite(1,i);
            build.emplace_back(make_pair(1,i));
        }
    }
    /*
    the connected graph with n nodes is a tree if and only if it has n - 1 edges
   build.size=close.size
    since build>close -> we build unneccesary roads
    close>build-> graph becomes disconnected
    hence proved
    */ 
   cout<<build.size()<<"\n";
    for(int i=0;i<build.size();i++){
        cout<<close[i].first<<" "<<close[i].second<<" "<<build[i].first<<" "<<build[i].second<<"\n";
    }
    // cout<<build.size()<<" "<<close.size();
    return 0;
}