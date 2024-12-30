#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int n;cin>>n;
    string s;cin>>s;
    int cntAdd=0,cntSub=0;
    for(auto c:s){
        cntAdd+=c=='+';
        cntSub+=c=='-';
    }
    int q;cin>>q;
    while(q--){
        int a,b;cin>>a>>b;
        ll num=1ll*b*(cntSub-cntAdd),den=a-b;
        bool ok;
        if(num==0){
            ok=1;
        }
        else if(den==0){
            ok=0;
        }
        else if(num%den==0 && -cntSub<=(num/den) && (num/den)<=cntAdd){
            ok=1;
        }
        else{
            ok=0;
        }
        cout<<(ok?"YES":"NO")<<"\n";
    }
    return 0;
}