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
    int n,m;cin>>n>>m;
    linker.assign(n+1,0);sz.assign(n+1,1);
    for(int i=0;i<=n;i++) linker[i]=i;
    while(m--){
        int k;cin>>k;
        if(k>0){
            // make x1 representative of the set
            int x1;cin>>x1;
            k--;
            while(k--){
                int x;cin>>x;
                unite(x1,x);
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<sz[find(i)]<<" "; // exclude user i himself
    }
    return 0;
}