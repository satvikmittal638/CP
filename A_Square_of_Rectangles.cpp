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
       vector<int> l(3),b(3);
       for(int i=0;i<3;i++) cin>>l[i]>>b[i];
       bool ok=0;
       if(l[0]>=b[0]){
        if(l[1]+l[2]==l[0] && b[1]==b[2] && b[0]+b[1]==l[0]) ok=1;
        if(l[0]==l[1] && l[0]==l[2] && (b[0]+b[1]+b[2])==l[0]) ok=1;
       }
       else{
        swap(l,b);
        if(l[1]+l[2]==l[0] && b[1]==b[2] && b[0]+b[1]==l[0]) ok=1;
        if(l[0]==l[1] && l[0]==l[2] && (b[0]+b[1]+b[2])==l[0]) ok=1;
       }
       cout<<(ok?"YES":"NO")<<"\n";
    }
    return 0;
}