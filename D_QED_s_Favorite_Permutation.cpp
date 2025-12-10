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
       vector<int> p(n);for(auto &i:p) {cin>>i;i--;}
       string s;cin>>s;
       vector<bool> canBeLR(n,0);
       int pmin=p[0],pmax=p[0];
       for(int i=0;i<n-1;i++){
        pmin=min(pmin,p[i]);
        pmax=max(pmax,p[i]);
        // split can be made here
        if(pmin==0 && pmax==i){
            canBeLR[i]=1; // L at i-th position possible
        }
       }
       int problems=0;
       for(int i=0;i<n-1;i++){
        if(s[i]=='L' && s[i+1]=='R' && !canBeLR[i]){
            problems++;
        }
       }
       while(q--){
        int i;cin>>i;i--;
        // it was already a problem here, which is resolved now
        if(s[i]=='L' && s[i+1]=='R' && !canBeLR[i]) problems--;
        else if(s[i-1]=='L' && s[i]=='R' && !canBeLR[i-1]) problems--;

        s[i]=(s[i]=='L'?'R':'L');
        // check for new problems
        if(s[i]=='L' && s[i+1]=='R' && !canBeLR[i]) problems++;
        else if(s[i-1]=='L' && s[i]=='R' && !canBeLR[i-1]) problems++;
        cout<<(problems==0?"YES":"NO")<<'\n';
       }
    }
    return 0;
}