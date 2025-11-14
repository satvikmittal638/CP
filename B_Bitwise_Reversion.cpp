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
       vector<int> a(3);cin>>a[0]>>a[1]>>a[2];
       bool ok=1;
       for(int i=0;i<31;i++){
        int mask=(1<<i);
        int cnt1=((a[0]&mask)!=0) + ((a[1]&mask)!=0) + ((a[2]&mask)!=0);
        if(cnt1==2) {
            ok=0;
            break;
        }
       }
       cout<<(ok?"YES":"NO")<<'\n';
    }
    return 0;
}