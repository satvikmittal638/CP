#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n,q;cin>>n>>q;
       string s;cin>>s;
       vector<set<int>> ind(3);
       for(int i=0;i<n;i++){
        int x=s[i]-'a';
        ind[x].insert(i);
       }
       while(q--){
        char x,y;cin>>x>>y;
        if(ind[x-'a'].size()==0 || x=='a') {
            continue;
        }
        if(y<x){
            int pos=*ind[x-'a'].begin();
                s[pos]=y;
                ind[x-'a'].erase(pos);
                ind[y-'a'].insert(pos);
            // cout<<pos<<" ";
        }
       }
       cout<<s<<"\n";
    }
    return 0;
}