#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

bool valid(int x, int y) {
    int mx = max(x, y), mn = min(x, y);
    return mx <= 2 * mn + 2;
}

int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int a,b,c,d;cin>>a>>b>>c>>d;
       if(valid(a,b) && valid(c-a,d-b)){
        cout<<"YES\n";
       }
       else{
        cout<<"NO\n";
       }
    }
    return 0;
}