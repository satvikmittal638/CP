#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<int> w(n);for(auto &i:w) cin>>i;
       // find the pair sum with the maxm frequency
       map<int,int> f;
       for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            f[w[i]+w[j]]++;
        }
       }
       int mx=INT_MIN;
       for(auto p:f){
        mx=max(mx,p.second);
       }
       cout<<mx/2<<"\n";
    }
    return 0;
}