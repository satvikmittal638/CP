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
       int n,x;cin>>n>>x;
       vector<int> a(n);for(auto &i:a) cin>>i;
        set<int> avoid;
        avoid.insert(x);
        int ans=1;// atleast 1 segment always forms due to a[i]!=x
       for(int i=0;i<n;i++){
        if(x%a[i]==0){
            // reset and start a new segment
            if(avoid.count(a[i])){
                avoid.clear();
                avoid.insert(x);
                ans++;
            }
            // warn future elts
            set<int> tmp;
            for(auto e:avoid){
                if(e%a[i]==0) tmp.insert(e/a[i]);
            }
            avoid.insert(all(tmp)); // copy back to avoid

        }
       }
       cout<<ans<<'\n';
    }
    return 0;
}