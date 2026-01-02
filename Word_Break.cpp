#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

int n;
string s;
unordered_set<string> dict;// for O(1) lookup

// ans for s[0,i]
int dp[1001];
bool rec(int i){
    if(i<0 || i>=s.size()) return 1;//empty string

    if(dp[i]!=-1) return dp[i];

    bool ans=0;
    // dict have words of length <= 20
    for(int j=i;j>=max(0,i-20);j--){
        // s[j,i] check in dict 
        string t = s.substr(j, i - j + 1);
        if(dict.count(t) && rec(j-1)){
            ans=1;
            break;
        }
    }
    return dp[i]=ans;

}

int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       dict.clear();
       cin>>n>>s;
       for(int i=0;i<n;i++){
        string t;cin>>t;
        dict.insert(t);
       }
       memset(dp,-1,sizeof(dp));
       cout<<(rec(s.size()-1)?"Yes":"No")<<'\n';

    }
    return 0;
}