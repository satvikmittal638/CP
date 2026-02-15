#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

#ifndef ONLINE_JUDGE
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
#else
#define error(args...)
#endif

int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n,h,l;cin>>n>>h>>l;
       int cntR=0,cntC=0,both=0;
       for(int i=0;i<n;i++){
        int a;cin>>a;
        if(a<=h && a<=l){
            both++;
        }
        else if(a<=h){
            cntR++;
        }
        else if(a<=l){
            cntC++;
        }
       }
       int prs=min(cntR,cntC);
       int left=abs(cntR-cntC);
       if(both>=left) {
           prs += left;       
           int remBoth = both - left; 
           prs += remBoth/2; 
       } else {
           prs += both;        
       }
       cout<<prs<<'\n';
    }
    return 0;
}