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
       bool x=0;
       for(int d=1;!x;d++){
        for(int i=0;!x && i<n;i++){
            cout<<(i+1)<<' '<<(i+d)%n+1<<endl;
            cin>>x;
        }
       }
    }
    return 0;
}