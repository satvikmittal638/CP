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
       if(n%2==0){
        cout<<"-1\n";
        continue;
       }
       cout<<1<<" ";
       for(int i=n;i>=2;i--){
        cout<<i<<" ";
       }
       cout<<"\n";
    }
    return 0;
}