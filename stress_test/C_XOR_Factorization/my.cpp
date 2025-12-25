#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define vint vector<int>
#define vll vector<ll>
#define pb push_back
typedef long long ll;

string bits(int n){
    string ans;
    while(n){
        if(n&1){
            ans.push_back('1');
        }
        else{ans.push_back('0');}
        n>>=1;
    }
    reverse(all(ans));
    return ans;
}
int main()
{
    int t;cin >> t;
    while(t--){
        int n,k;cin >> n >> k;

        if(k&1){
            for(int i = 0;i<k;i++){
                cout << n << " ";
            }
            cout << '\n';
        }
        else{
            string ans = bits(n);
            int sz = ans.size();
            vint v(k,0);
            for(int i = 1;i<k;i++){
                v[i] = (v[i]^(1<<(sz-1)));
            }
            int i = 1;
            while(ans[i] == '0'){i++;}
            int ct = 1;
            int skip = 1;
            for(int j = i;j<sz;j++){
                if(ans[j] == '1'){
                    if(skip == k){
                        for(int w = 1;w<k;w++){
                            v[w] = (v[w]^(1<<(sz-j-1)));
                        }
                        continue;
                    }
                    for(int w = 0;w<k;w++){
                        if(w == skip){continue;}
                        v[w] = (v[w]^(1<<(sz-j-1)));
                    }
                    if(skip < k){ct = skip + 1;}
                    skip++;
                }
                else{
                    for(int w = 0;w<(ct - (ct&1));w++){
                        v[w] = (v[w]^(1<<(sz-j-1)));
                    }
                }
            }
            for(int i = 0;i<k;i++){
                cout << v[i] << " ";
            }
            cout << '\n';
        }
    }
}