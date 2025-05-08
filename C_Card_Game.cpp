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
       set<int> a,b;
       for(int i=1;i<=n;i++){
        char c;cin>>c;
        if(c=='A') a.insert(i);
        else b.insert(i);
       }
       if(*a.begin()==1 && *a.rbegin()==n){
        cout<<"Alice\n";
        continue;
       }
       if(*b.begin()==1 && *b.rbegin()==n){
        cout<<"Bob\n";
        continue;
       }
       if(a.find(n)!=a.end() && a.find(n-1)!=a.end()){
        cout<<"Alice\n";
        continue;
       }
       if(b.find(n)!=b.end() && b.find(n-1)!=b.end()){
        cout<<"Bob\n";
        continue;
       }
       if(b.find(n)!=b.end() && b.find(n-1)!=b.end()){
        cout<<"Bob\n";
        continue;
       }




    }
    return 0;
}