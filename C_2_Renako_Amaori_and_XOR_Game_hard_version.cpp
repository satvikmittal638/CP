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

       // play the game bitwise
       bool tie=1;
       for(int i=31;i>=0;i--){
        int mask=(1<<i);
           int dif = 0;
           int last_idx = -1;

           for(int i = 0; i < n; i++){
            int bita=(a[i]&mask)!=0,bitb=(b[i]&mask)!=0;
               if(bita != bitb){
                   dif++;
                   last_idx = i;
               }
           }
           // if diff is odd, person with last move wins
           if(dif %2!=0){
            tie=0;
               if(last_idx % 2 == 0) cout << "Ajisai";
               else cout << "Mai";
               break;
           }

       }
       if(tie) cout<<"Tie";
       cout << '\n';
    }
    return 0;
}