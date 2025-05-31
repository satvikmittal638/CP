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
       int n,k;cin>>n>>k;
       string s;cin>>s;
       int cnt0=count(all(s),'0'),cnt1=s.length()-cnt0;
       int pair0=cnt0/2,pair1=cnt1/2;
       if(pair0+pair1>=k){
        int x=(cnt0-cnt1)/4 + k/2;
        if((cnt0-cnt1)%4==0 && k%2==0 && x>=0){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
       }
       else{
        cout<<"NO\n";
       }
    }
    return 0;
}