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
       vector<string> s(n);
       for(int i=0;i<n;i++) cin>>s[i];
       bool ok=1;
       for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            // just 2 impossible 2X2 matrices
            if(
                s[i][j]=='1' && s[i][j+1]=='0' && s[i+1][j]=='0' && s[i+1][j+1]=='1' ||
                s[i][j]=='1' && s[i][j+1]=='0' && s[i+1][j]=='0' && s[i+1][j+1]=='0' 
            ){
                ok=0;break;
            }
        }
       }
       cout<<(ok?"YES":"NO")<<"\n";
    }
    return 0;
}