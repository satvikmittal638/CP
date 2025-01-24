#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

long long fastmmi(long long a, long long mod) {
    long long res = 1, exp = mod - 2;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        exp /= 2;
    }
    return res;
}

int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n,m;cin>>n>>m;
       vector<int> a(n);
       ll prod=1;
       for(auto &i:a) {
        cin>>i        prod=(prod*i)%m;
       }
       cout<<prod;
       int l=0,r=n-1;
        string s;cin>>s;
        for(auto c:s){
            cout<<prod<<" ";
            if(c=='L'){
                prod*=fastmmi(a[l],m);
                l++;
            }
            else{
                prod*=fastmmi(a[r],m);
                r--;
            }
        }
        cout<<"\n";
    }
    return 0;
}