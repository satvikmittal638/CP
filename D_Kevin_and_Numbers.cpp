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
       int n,m;cin>>n>>m;
       priority_queue<int> a,b;
       for(int i=0;i<n;i++){
        int x;cin>>x;
        a.push(x);
       }
       for(int i=0;i<m;i++){
        int x;cin>>x;
        b.push(x);
       }
       bool ok=1;
       while(a.size()){
        if(b.empty() || b.size()>a.size()){
            ok=0;break;
        }
        int x=b.top();b.pop();
        if(x==a.top()){
            a.pop();
        }
        else{
            b.push(x/2);
            b.push((x+1)/2);
        }
       }
       ok&=b.empty();

       cout<<(ok?"Yes":"No")<<"\n";
       

    }
    return 0;
}