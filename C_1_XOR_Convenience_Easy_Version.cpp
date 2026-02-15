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
       vector<bool> used(n+1,0);
       used[1]=1;
       p[n]=1;
       for(int i=2;i<n;i++){
        p[i]=i^1;
        used[p[i]]=1;
       }
       for(int i=1;i<=n;i++){
        if(!used[i]) {
            p[1]=i;
            break;
        }
       }
       if((n+1)&n!=0){
        cout<<"-1\n";
        continue;
       }
       for(int i=1;i<=n;i++) cout<<p[i]<<' ';
       cout<<'\n';
    }
    return 0;
}