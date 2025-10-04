#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
// DSU Implementation
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
//
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n,m;cin>>n>>m;
       // DSU initialize
       linker.assign(n+1,0);sz.assign(n+1,0);
        numOfSets=n;mxSz=1;
        for(int i=0;i<=n;i++) linker[i]=i; // initially n sets


       // mxJump[i][j] is the maxm no. of jumps of length j u can make from i
       // Its only initialized for starting points (a[i])
       vector<vector<int>> mxJump(n+1,vector<int>(11,0));

       while(m--){
        int a,d,k;cin>>a>>d>>k;
        mxJump[a][d]=max(mxJump[a][d],k);
       }
       for(int i=1;i<=n;i++){
        for(int j=1;j<=10;j++){
            int pos=i,cnt_jumps=mxJump[i][j];
            while(cnt_jumps>0){
                cnt_jumps--;
                unite(pos,pos+j);
                mxJump[pos][j]=0;// jumped from here once, so can't jump again from here
                pos+=j;
                cnt_jumps=max(cnt_jumps,mxJump[pos][j]); // update cnt_jumps to adjust for new APs starting at further positions
            }
        }
       }
       cout<<numOfSets<<'\n';
    }
    return 0;
}