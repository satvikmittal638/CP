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
       vector<int> a(n),p_xor(n,0);
       for(int i=0;i<n;i++){
        cin>>a[i];
        p_xor[i]=a[i]^(i>0?p_xor[i-1]:0);
       }
       int x0=0,x1=0;
       string s;cin>>s;
       for(int i=0;i<s.length();i++){
        if(s[i]=='0') x0^=a[i];
        else x1^=a[i];
       }
       int q;cin>>q;
       while(q--){
        int tp;cin>>tp;
        if(tp==1){
            int l,r;cin>>l>>r;l--;r--;
            x0^=p_xor[r]^(l>0?p_xor[l-1]:0);
            x1^=p_xor[r]^(l>0?p_xor[l-1]:0);
        }
        else{
            int g;cin>>g;
            cout<<(g==0?x0:x1)<<" ";
        }
       }
       cout<<"\n";
    }
    return 0;
}