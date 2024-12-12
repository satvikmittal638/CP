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
int size(int a){
    return sz[find(a)];
}
int main()
{
    int n,m;cin>>n>>m;
    linker.assign(n+1,0);sz.assign(n+1,1);
    for(int i=0;i<=n;i++) linker[i]=i;
    while(m--){
        int x,y;cin>>x>>y;
        unite(x,y);
    }
    set<int> parents;
    for(int i=1;i<=n;i++){
        parents.insert(find(i));
    }
    int power=0;
    for(auto p:parents){
        power+=sz[p]-1;
    }
    cout<<(long long)pow(2,power);
    return 0;
}