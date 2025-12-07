#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
bool hasDigit(const string &s) {
    for(char c : s)
        if(isdigit(c)) return 1;
    return 0;
}
int main()
{
fastio;
    vector<vector<ll>> a;
    vector<char> op;
    string s;

    while (1) {
        if(!getline(cin, s)) break;
        if(s.empty()) continue;

        if (!hasDigit(s)) { // operator row detected
            stringstream ss(s);
            char c;
            while(ss >> c)
                op.push_back(c);
            break;
        }

        // numeric row
        stringstream ss(s);
        vector<ll> row;
        ll x;
        while (ss >> x)
            row.push_back(x);
        a.push_back(row);
    }
    ll ans=0ll;
    for(int j=0;j<a[0].size();j++){
        ll cur=0ll;
        if(op[j]=='*') cur=1ll;
        for(int i=0;i<a.size();i++){
            if(op[j]=='*'){
                cur*=a[i][j];
            }
            else{
                cur+=a[i][j];
            }
        }
        ans+=cur;
    }
    cout<<ans<<'\n';


    return 0;
}