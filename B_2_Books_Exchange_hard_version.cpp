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

int size(int a){
    return sz[find(a)];
}

bool isSameSet(int a,int b){
    a=find(a);b=find(b);
    return a==b;
}


int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
        linker.assign(n+1,0);sz.assign(n+1,1);
        for(int i=0;i<=n;i++) linker[i]=i;

       for(int i=1;i<=n;i++){
        int p;cin>>p;
        unite(i,p);
       }
       for(int i=1;i<=n;i++){
        cout<<size(i)<<" ";
       }
       cout<<"\n";


    }
    return 0;
}