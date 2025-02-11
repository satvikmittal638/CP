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
       int cnt=0;
       for(int i=0;i<s.length()-1;i++){
        if(s[i]==s[i+1]) cnt++;
       }
       if(cnt>0) cout<<"1\n";
       else cout<<s.length()<<"\n";
    }
    return 0;
}