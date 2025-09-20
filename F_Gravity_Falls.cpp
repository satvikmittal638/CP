#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const int MAX=2*1e5+1;
int main()
{
    fastio;
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<vector<int>> a(n,vector<int>());
       for(int i=0;i<n;i++){
        int k;cin>>k;
        a[i].resize(k); // Minor optimization: resize once
        for(int j=0;j<k;j++){
            cin>>a[i][j];
        }
       }
       
       // CHANGE 1: Sort efficiently by passing vectors by reference (const auto&)
       // Also use '<' instead of '<=' for strict ordering, which std::sort requires.
       sort(all(a),[&](const auto& x, const auto& y){
        return x.size() < y.size();
       });
       
       if (a.empty()) { // Edge case for safety
           cout << '\n';
           continue;
       }

       int len = a.back().size(); // Use int for sizes
       vector<int> byLen(len+1,n);
       int cur = n;
       for (int l = len; l >= 0; --l) {
           // Use static_cast for safe comparison between signed and unsigned types
           while (cur > 0 && a[cur-1].size() >= l) {
               cur--;
           }
           byLen[l] = cur;
       }
       
       vector<int> ans;
       ans.reserve(len);

       while(ans.size() < len){
        int i = ans.size(); 
        if (i + 1 > len) break;

        int start = byLen[i+1];
        
        auto it = min_element(
            a.begin() + start, a.end(),
            [&](const vector<int>& x, const vector<int>& y) {
                return lexicographical_compare(
                    x.begin() + i, x.end(),
                    y.begin() + i, y.end()
                );
            });

        const vector<int>& toUse = *it;
        ans.insert(ans.end(), toUse.begin() + i, toUse.end());
       }

       for(auto e:ans) cout<<e<<' ';
       cout<<'\n';
    }
    return 0;
}