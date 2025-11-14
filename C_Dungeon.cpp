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
       int n,m;cin>>n>>m;
       multiset<ll> swords;
       for(int i=0; i<n; i++){
            ll a_i;
            cin >> a_i;
            swords.insert(a_i);
       }

       vector<pair<ll,ll>> b_c(m);
       for(int i=0;i<m;i++) cin>>b_c[i].first; 
       for(int i=0;i<m;i++) cin>>b_c[i].second;

       sort(all(b_c),[&](auto p1,auto p2){
        if(p1.first!=p2.first) return p1.first<p2.first;
        else return p1.second>p2.second;
       });

       int kills = 0;
       
       for(int i=0; i<m; i++){
            ll b = b_c[i].first;
            ll c = b_c[i].second;

            if(c>0){
                // find weakest sword in our pool that can kill this monster
                auto it = swords.lower_bound(b);
    
                if(it != swords.end()){
                    ll sword_used = *it;
                    
                    swords.erase(it);// dissappear
                    kills++;
                    
                    swords.insert(max(sword_used, c));
                }
            }
       }
       for(int i=m-1; i>=0; i--){
            ll b = b_c[i].first;
            ll c = b_c[i].second;

            if(c==0){
                // find weakest sword in our pool that can kill this monster
                auto it = swords.lower_bound(b);
    
                if(it != swords.end()){
                    ll sword_used = *it;
                    swords.erase(it);// dissappear
                    kills++;
                }
            }
       }

       
       cout << kills << '\n';
    }
    return 0;
}