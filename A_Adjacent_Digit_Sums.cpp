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
        int x,y;cin>>x>>y;
        if(y-x==1) cout<<"Yes";
        else if(x>y && (x-y)%9==8) cout<<"Yes";
        else cout<<"No";
        cout<<"\n";
    }
    return 0;
}