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
       string s,t;cin>>s>>t;
       int i=s.length()-1,j=t.length()-1;
       while(i>=0 && j>=0){
        if(s[i]==t[j]){
            i--;j--;
        }else{
            i-=2; // delete 2 characters
        }
       }
       cout<<(j<0?"YES":"NO")<<"\n";
    }
    return 0;
}