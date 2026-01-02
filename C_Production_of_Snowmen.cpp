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
       vector<int> a(n), b(n), c(n);
       for(auto &i : a) cin >> i;
       for(auto &i : b) cin >> i;
       for(auto &i : c) cin >> i;

       //count how many cyclic shifts satisfy v1[i] < v2[i+s]
       auto countValidShifts = [&](const vector<int>& v1, const vector<int>& v2) {
            ll valid_cnt = 0;
            for(int s = 0; s < n; s++) { // try every shift 
                bool ok = 1;
                for(int i = 0; i < n; i++) {
                    if(v1[i] >= v2[(i + s) % n]) {
                        ok = 0;
                        break;
                    }
                }
                if(ok) valid_cnt++;
            }
            return valid_cnt;
       };

       // count valid shifts for A -> B
       ll countAB = countValidShifts(a, b);
       
       // count valid shifts for B -> C
       ll countBC = countValidShifts(b, c);

       // total = (valid A->B) * (valid B->C) * n (start positions)
       cout << countAB * countBC * n << '\n';
    }
    return 0;
}