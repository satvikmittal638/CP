#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define vint vector<int>
#define vvint vector<vector<int>>
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define pll pair<ll,ll> 
#define vpll vector<pll> 
#define pb push_back
#define ff first
#define ss second
#define vinp(v) for(auto &x : (v)) cin >> x
#define vout(v) for(auto &x : (v)){cout<<x<<' ';}cout << '\n'
typedef long long ll;
const int M = 998244353;

int main()
{
    //g++ -std=gnu++23 -O2 main.cpp -o main && ./main < input.txt > output.txt
    int t;cin >> t;
    while(t--){
        int n,m;cin>>n>>m;
        string s;cin>>s;
        vint v(m);vinp(v);
        // vout(v);
        int sum = n;
        int mini = n;
        for(int i = 0;i<m;i++){
            sum += v[i];
            mini = min(mini,sum);
        }
        int fin = sum;
        // cout<<fin<<'\n';continue;
        string ans;
        if(mini <= 0){cout << 0 << '\n';}
        else{
            for(int i = 1;i<=mini;i++){
                ans.pb(s[i-1]);
            }
            for(int i = mini+1;i<=fin;i++){
                ans.pb('0');
            }
            cout << ans << '\n';
        }
    }
}