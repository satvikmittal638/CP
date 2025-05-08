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
       vector<int> p(n);for(auto &i:p) cin>>i;
       // find elts which form the last elt of LIS of size 2
       int mn=INT_MAX,mnW=INT_MAX;
       int cnt=0;
       for(int i=0;i<n;i++){
        if(p[i]>mn && p[i]<mnW) {
            // p[i] is a winning elt
            cnt++;
            mnW=min(mnW,p[i]);
        }
        mn=min(mn,p[i]);
       }
       cout<<cnt<<"\n";
    }
    return 0;
}