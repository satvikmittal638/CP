#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
    fastio;
    int tt; cin >> tt;
    while(tt--){
       int n, k; cin >> n >> k;
       vector<set<char>> charAtPos(n + 1);
       
       for(int i = 0; i < k; i++) {
            string s; cin >> s;
            for(int j = 0; j < n; j++) {
                charAtPos[j + 1].insert(s[j]); 
            }
       }

       auto getStr = [&](int d)->string {
            string t = "";
            for(int r = 1; r <= d; r++){
                char foundChar = 0;
                for(char c = 'a'; c <= 'z'; c++){
                    bool isPos = 1;
                    for(int j = r; j <= n; j += d){
                        if(charAtPos[j].find(c) == charAtPos[j].end()){
                            isPos = 0;
                            break;
                        }
                    }
                    if(isPos){
                        foundChar = c;
                        break;
                    }
                }
                
                if(foundChar) t += foundChar;
                else return "";
            }
            return t;
       };

       string ans = "";
       int min_d = n + 1;

       // check all divisors
       for(int d = 1; d * d <= n; d++){
            if(n % d == 0){
                int d1 = d;
                int d2 = n / d;
                string t1 = getStr(d1);
                if(t1.size() == d1){
                    ans = "";
                    for(int i=0; i < n/d1; i++) ans += t1;
                    min_d = d1;
                    break; 
                }

                string t2 = getStr(d2);
                if(t2.size() == d2 && d2 < min_d){
                     min_d = d2;
                     ans = "";
                     for(int i=0; i < n/d2; i++) ans += t2;
                }
            }
       }

       cout << ans << "\n";
    }
    return 0;
}