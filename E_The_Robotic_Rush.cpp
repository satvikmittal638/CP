#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const int INF=1e9+10;

int main(){
    fastio;
    int tt; cin>>tt;
    while(tt--){
        int n,m,k; cin>>n>>m>>k;
        vector<int> a(n), b(m);
        for(auto &i:a) cin>>i;
        for(auto &i:b) cin>>i;
        sort(all(a));
        sort(all(b));
        string s; cin>>s;
        // find delL, delR
        set<pair<int,int>> nearbyDels;

        for(int i=0;i<n;i++){
            int delL = INF-1, delR = INF-1;
            // find first b>a[i]
            auto it = upper_bound(all(b), a[i]);
            
            if(it != b.end())
                delR = *it - a[i];

            if(it != b.begin()){
                it--;// largest b[i]<=a[i]
                delL = a[i] - *it;
            }
            // add
            nearbyDels.emplace(-delL, i);
            nearbyDels.emplace(delR, i);
        }

        vector<bool> died(n,0);
        int del = 0, ans = n;

        for(int i=0;i<k;i++){
            del += (s[i]=='R') - (s[i]=='L');
            // remove all bots whose either delta is the current delta
            auto it1 = nearbyDels.lower_bound({del, -INF});
            auto it2 = nearbyDels.upper_bound({del, INF});

            vector<int> killed;

            for(auto it = it1; it != it2; ++it){
                int id = it->second;
                if(!died[id]){
                    died[id] = 1;
                    killed.push_back(id);
                }
            }

            // erase all matching entries
            nearbyDels.erase(it1, it2);

            ans -= killed.size();  
            cout << ans << ' ';
        }
        cout << '\n';
    }
    return 0;
}