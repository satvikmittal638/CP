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
       int n,k;cin>>n>>k;k--;
       int curH;
       set<int> st;
       for(int i=0;i<n;i++){
        int x;cin>>x;st.insert(x);
        if(i==k) curH=x;
       }
       vector<int> h; // compressed and sorted array > curH
       for(auto e:st) if(e>curH) h.push_back(e);

       int curT=1;
       bool ok=1;
       for(int i=0;i<h.size();i++){
        if(curH<(curT+h[i]-curH)-1) {
            ok=0;break;
        }
        curT+=h[i]-curH;// climb up
        curH=h[i];
       }
       cout<<(ok?"YES":"NO")<<"\n";
    }
    return 0;
}