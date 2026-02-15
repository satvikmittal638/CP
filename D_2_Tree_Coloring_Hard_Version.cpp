#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
vector<vector<int>> adj,nodesByDepth;
vector<int> cntDepth,cntChild,par;
void dfs(int u,int p,int d){
    par[u]=p;
    nodesByDepth[d].emplace_back(u);
    cntDepth[d]++;
    for(auto v:adj[u]){
        if(v==p) continue; // only 1 back-edge for a tree
        dfs(v,u,d+1);
    }
}

int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       adj.assign(n,vector<int>());
       nodesByDepth.assign(n,vector<int>());
       cntDepth.assign(n,0);
       cntChild.assign(n,0);
       par.assign(n,-1);
       
       for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
       }
       // now we need no. of nodes at a given depth d 
       dfs(0,-1,0);
       // and no. of direct children of a node u
       cntChild[0]=adj[0].size(); // no backedge for root
       for(int u=1;u<n;u++){
        cntChild[u]=adj[u].size()-1; // 1 back-edge to parent
       }
       int k=max(1+*max_element(all(cntChild)),*max_element(all(cntDepth)));

       //---MODIFY BELOW---
       // now lets color the nodes in 'k' colors
       vector<int> nodeColor(n,-1);
       for(int d=0;d<n;d++){
        // sort nodes at a depth by the color of their parent
        sort(all(nodesByDepth[d]),[&](int u1,int u2){
            return nodeColor[par[u1]]<nodeColor[par[u2]];
        });
        // now all nodes whose parents have same color are together in blocks
        // c[u[i]]=(i+del)modk
        // find all invalid dels by c[par[u[i]]]-i modk
        set<int> used;
        for(int i=0;i<nodesByDepth[d].size();i++){
            int u=nodesByDepth[d][i];
            used.insert((nodeColor[par[u]]-i+k)%k);
        }
        // find first unused del
        int del=0;
        for(int z=0;z<k;z++){
            if(used.count(z)==0){
                del=z;
                break;
            }
        }
        // now color the nodes
        for(int i=0;i<nodesByDepth[d].size();i++){
            int u=nodesByDepth[d][i];
            nodeColor[u]=(i+del)%k;
        }
       }

       // now invert the color map to form grps of same opn
       vector<vector<int>> colorToNode(k);
       for(int u=0;u<n;u++){
        colorToNode[nodeColor[u]].push_back(u);
       }
       cout<<k<<'\n';
       for(auto op:colorToNode){
        cout<<op.size()<<' ';
        for(auto u:op) cout<<u+1<<' ';// 1-indexed
        cout<<'\n';
       }

       
    }
    return 0;
}