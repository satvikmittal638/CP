#include<bits/stdc++.h>
using namespace std;
map<string,vector<string>> adj;

void dfs(string v,int& mxLen){
    static int curLen=1;// polycarp always in repost chain
    
    for(auto u:adj[v]){
        curLen++;
        dfs(u,mxLen);
    }
    mxLen=max(curLen,mxLen);
    curLen--; // rollback previous state
    
}

int main()
{
    int n;cin>>n;
    while(n--){
        string name1,sep,name2;cin>>name1>>sep>>name2;
       
        transform(name1.begin(), name1.end(), name1.begin(), [](unsigned char c) {
            return tolower(c);
        });
        transform(name2.begin(), name2.end(), name2.begin(), [](unsigned char c) {
            return tolower(c);
        });
        adj[name2].push_back(name1);
    }
  
    int mxLen=INT_MIN;
    dfs("polycarp",mxLen);
    cout<<mxLen;
    return 0;
}