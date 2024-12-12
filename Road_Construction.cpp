#include<bits/stdc++.h>
using namespace std;
vector<int> linker,sz;
int numOfSets,mxSz;

int find(int a){
    while(a!=linker[a]){
        a=linker[a]; // move to the parent until a self loop is found
    }
    return a;
}

void unite(int a,int b){
    a=find(a);
    b=find(b);
    if(a!=b){
        // merge shorter segment into larger one
        if(sz[a]<sz[b]) swap(a,b);
        // b has shorter segment,a has longer now
        // merge b to a
        sz[a]+=sz[b];
        linker[b]=a;
        numOfSets--;
        mxSz=max(mxSz,sz[a]);
    }
}

int main()
{
    int n,m;cin>>n>>m;
    linker.assign(n+1,0);sz.assign(n+1,1);
    numOfSets=n;mxSz=1;
    for(int i=0;i<=n;i++) linker[i]=i;
    while(m--){
        int a,b;cin>>a>>b;
        unite(a,b);
        cout<<numOfSets<<" "<<mxSz<<"\n";
    }
    return 0;
}