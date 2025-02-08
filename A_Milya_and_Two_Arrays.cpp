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
       set<int> sta,stb;
       for(int i=0;i<n;i++){
        int a;cin>>a;sta.insert(a);
       }
       for(int i=0;i<n;i++){
        int b;cin>>b;stb.insert(b);
       }
       if((sta.size()>=2 && stb.size()>=2) || (sta.size()>=3 && stb.size()==1) || (stb.size()>=3 && sta.size()==1)){
        cout<<"YES";
       }
       else cout<<"NO";
       cout<<"\n";

    
    }
    return 0;
}