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
       string s;cin>>s;
       int n=s.length();
       int m;cin>>m;
       string l,r;cin>>l>>r;
       int i=0,j=0;
       for(;i<m;i++){
        char dig=l[i];
        while(j<n){
            if(s[j]==dig){
                if(dig<r[i]) {
                    dig++;
                }
                else {
                    break;
                }
            }
            else{
                j++;
            }
        }
        if(j>=n) break;
        // cout<<i<<" "<<j<<"  ";
       }
    //    cout<<i<<" "<<j<<"\n";
       cout<<((j==n && i<m)?"YES":"NO")<<"\n";
    }
    return 0;
}