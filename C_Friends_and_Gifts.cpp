#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int n;cin>>n;
    vector<int> f(n);for(auto &i:f) {
        cin>>i;
        i--;
    }
    vector<bool> in(n),out(n);
    for(int i=0;i<n;i++){
        if(f[i]!=0) {
            out[i]=1;
            in[f[i]]=1;
        }
    }
    vector<int> isolated;
    for(int i=0;i<n;i++){
        if(!in[i] && !out[i]) isolated.push_back(i);
    }
    // make a cycle of isolated vertices
    int k=isolated.size();
    if(k>1){
        for(int i=0;i<k-1;i++){
            f[isolated[i]]=isolated[i+1];
        }
        f[isolated[k-1]]=isolated[0]; // complete the cycle
    }
    else if(k==1){
        for(int i=0;i<n;i++){
            if(!out[i]) f[i]=isolated[0];
        }
    }
    else{
        
    }
    return 0;
}