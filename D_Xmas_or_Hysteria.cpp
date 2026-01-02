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
       int n,m;cin>>n>>m;
       vector<pair<int,int>> h(n);
       for(int i=0;i<n;i++){
        cin>>h[i].first;
        h[i].second=i+1;
       }
       sort(all(h));
       vector<int> a(n);
       for(int i=0;i<n;i++){
        a[i]=h[i].first;
       }
       if(m>n/2){
        cout<<"-1\n";
        continue;
       }
       vector<pair<int,int>> ans;
       if(m>0){
        // now first n-2m form a chain of attacks (i,i+1) to only let a[n-2m-1] attack ahead and intefere with reserved block
        for(int i=0;i<n-2*m;i++){
            ans.emplace_back(h[i].second,h[i+1].second); 
        }
        // last m survive
        // last m attack prvs ms
        for(int i=n-1;i>=n-m;i--){
            ans.emplace_back(h[i].second,h[i-m].second);
        }

       }
       else{
        // check if possible to kill the largest elf
            ll sum_others = 0;
            for(int i = 0; i < n - 1; i++) sum_others += a[i];

            if(sum_others < a[n-1]) {
                cout << "-1\n";
                continue;
            }

            // find the split point k
            // we need the largest elves to kill the King.
            // iterate backwards to find the minm no. of large elves needed
            ll cur_dmg = 0;
            int k = n - 1; 
            
            for(int i = n - 2; i >= 0; i--) {
                cur_dmg += a[i];
                k = i;
                if(cur_dmg >= a[n-1]) break;
            }

            //  (0 to k-1) attack their right neighbor to die
            for(int i = 0; i < k; i++) {
                ans.emplace_back(h[i].second, h[i+1].second);
            }

            //(k to n-2) attack the King (n-1).
            for(int i = k; i < n - 1; i++) {
                ans.emplace_back(h[i].second, h[n-1].second);
            }
       }
       cout<<ans.size()<<'\n';
       for(auto [x,y]:ans) cout<<x<<' '<<y<<'\n';
    }
    return 0;
}