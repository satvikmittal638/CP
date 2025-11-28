#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
    fastio;
    int tt; cin >> tt;
    while(tt--){
       int n; cin >> n;
       vector<int> a(n), b(n);
       
       for(auto &i : a) cin >> i;
       for(auto &i : b) cin >> i;

       int dif = 0;
       int last_idx = -1;

       for(int i = 0; i < n; i++){
           if(a[i] != b[i]){
               dif++;
               last_idx = i;
           }
       }
       if(dif % 2 == 0){
           cout << "Tie";
       }
       // if diff is odd, person with last move wins
       else{
           if(last_idx % 2 == 0) cout << "Ajisai";
           else cout << "Mai";
       }
       cout << '\n';
    }
    return 0;
}