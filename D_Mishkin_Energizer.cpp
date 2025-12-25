#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

int main()
{
    fastio;
    int tt; cin >> tt;
    while(tt--){
       int n; cin >> n;
       string s; cin >> s;
       
       auto get_sorted_counts = [&](string &str) {
           map<char,int> cnt;
           for(auto c : str) cnt[c]++;
           vector<pair<int,char>> vc;
           if(cnt.find('L') == cnt.end()) cnt['L'] = 0;
           if(cnt.find('I') == cnt.end()) cnt['I'] = 0;
           if(cnt.find('T') == cnt.end()) cnt['T'] = 0;
           for(auto [c, f] : cnt) vc.emplace_back(f, c);
           sort(all(vc));
           return vc;
       };

       auto vc = get_sorted_counts(s);

       if(vc[2].first == n){
           cout << "-1\n";
           continue;
       }
       
       char c1, c2;
       auto spin = [&](char c){
           if(c == 'L') c1 = 'I', c2 = 'T';
           if(c == 'I') c1 = 'L', c2 = 'T';
           if(c == 'T') c1 = 'L', c2 = 'I';
       };

       vector<int> ops;
       int z = 0;
       bool ok = 0;
       
       for(int _ = 0; _ < 2*n; _++){
           vc = get_sorted_counts(s);
           if(vc[0].first == vc[1].first && vc[1].first == vc[2].first){
               ok = 1;
               break;
           }

           // Priority 1: Pick based on z (alternating strategy)
           // Priority 2: If priority 1 fails, pick the other one
           bool inserted = 0;
           
           // Try the preferred index (z) first, then the other index (z^1)
           for(int k : {z, z^1}) {
               char target = vc[k].second;
               spin(target);
               
               for(int i = 0; i < s.length() - 1; i++){
                   if((s[i] == c1 && s[i+1] == c2) || (s[i] == c2 && s[i+1] == c1)){
                       s.insert(s.begin() + i + 1, target);
                       ops.emplace_back(i + 1);
                       inserted = 1;
                       break;
                   }
               }
               if(inserted) break; // Stop if we found a move
           }

           if(!inserted) break; // Impossible to proceed

           z ^= 1; // Toggle preference for next turn
       }

    //    cout<<s<<'\n';
       if(!ok){
            cout << "-1\n";
       } else {
            cout << ops.size() << '\n';
            for(auto e : ops){
                cout << e << '\n';
            }
       }
    }
    return 0;
}