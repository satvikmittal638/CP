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
       int n;cin>>n;
       map<int,int> cnt;
       for(int i=0;i<n;i++){
        int a;cin>>a;
        cnt[a]++;
       }
       int x=-1;
       for(auto &p:cnt){
        if(p.second>1){
            x=p.first;
            break;
        }
       }
       if(x!=-1){
            cout<<"1\n"<<x<<"\n";
       }
       else{
        cout<<x<<"\n";
       }
    }
    return 0;
}