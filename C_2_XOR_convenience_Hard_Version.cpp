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
       int n;cin>>n;
       vector<int> p(n+1,0);
        bool ok=0;
       for(int pn=1;pn<=n;pn++){
           vector<bool> used(n+1,0);
           used[pn]=1;
           p[n]=pn;
           for(int i=1;i<n;i++){
            if(i==pn) continue;
            p[i]=i^p[n];
            used[p[i]]=1;
           }
           int tgt=0;
           for(int i=1;i<=n;i++){
            if(!used[i]) {
                p[pn]=i;
                tgt=p[pn]^pn;
                break;
            }
           }
           for(int i=pn;i<=n;i++){
            if(p[i]^i==tgt){
                ok=1;
                break;
            }
           }
           for(int i=1;i<=n;i++){
            if(p[i]>n){
                ok=0;
                break;
            }
           }
       }
       if(!ok){
        cout<<"-1\n";
        continue;
       }
       for(int i=1;i<=n;i++) cout<<p[i]<<' ';
       cout<<'\n';
    }
    return 0;
}