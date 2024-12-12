#include<bits/stdc++.h>
using namespace std;

vector<int> linker,sz;
vector<vector<int>> elts;
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
        // transfer elts
        elts[a].insert(elts[a].end(), elts[b].begin(), elts[b].end());
        elts[b].clear();
        sz[a]+=sz[b];
        linker[b]=a;
    }
}

int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n,k;cin>>n>>k;
       string s,t;cin>>s>>t;
       linker.assign(n,0);
       sz.assign(n,1);
       elts.assign(n,vector<int>());
       for(int i=0;i<n;i++) {
        linker[i]=i;
        elts[i].emplace_back(i);
       }
       for(int i=0;i<n;i++){
        if(i+k<n) unite(i,i+k);
        if(i+k+1<n) unite(i,i+k+1);
       }
    //   for(int i=0;i<n;i++){
    //     for(auto e:elts[i]){
    //         cout<<e<<" ";
    //     }
    //     cout<<"\n";
    //   }
       bool isPos=1;
       for(int i=0;i<n;i++){
        vector<int> f_s(26,0),f_t(26,0);
        for(auto e:elts[i]){
            f_s[s[e]-'a']++;
            f_t[t[e]-'a']++;
        }

        for(int i=0;i<f_s.size();i++){
            if(f_s[i]!=f_t[i]){
                isPos=0;break;
            }
        }
        if(!isPos) break;
       }
        cout<<(isPos?"YES\n":"NO\n");
    }
    return 0;
}