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
       string s; cin >> s;
       
       bool has2025 = 0;
       bool has2026 = 0;
       
    for(int i = 0; i <= n - 4; i++){
        string sub = s.substr(i, 4);
        if(sub == "2026"){
            has2026 = 1;
        }
        if(sub == "2025"){
            has2025 = 1;
        }
    }

       
       if (has2026 || !has2025) {
           cout << 0 << '\n';
       } else {
           cout << 1 << '\n';
       }
    }
    return 0;
}