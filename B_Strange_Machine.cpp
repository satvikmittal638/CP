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
       int n,q;cin>>n>>q;
       string s;cin>>s;
       while(q--){
        int a;cin>>a;
        // O(logA)
        int ans=0;
        if(count(all(s),'A')<n){
            // simulate
            int i=0;
            while(a){
                if(s[i]=='A') a--;
                else a=a/2;
                i=(i+1)%n; // circular increment
                ans++;
            }
        }
        else{
            ans=a;
        }
        cout<<ans<<'\n';
       }
    }
    return 0;
}