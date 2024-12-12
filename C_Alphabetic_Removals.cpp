#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;cin>>n>>k;
    string s;cin>>s;
    vector<vector<int>> alphaInd(26,vector<int>());
    for(int i=0;i<n;i++){
    alphaInd[s[i]-'a'].emplace_back(i);
    }
   for(int i=0;k>0 && i<26;i++){
    for(auto ind:alphaInd[i]){
        if(k>0){
            s[ind]='_';
            k--;
        }
        else break;
    }
   }
   for(int i=0;i<n;i++){
    if(s[i]!='_') cout<<s[i];
   }
    return 0;
}