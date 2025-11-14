#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    string s;cin>>s;
    int n=s.length();
    s=' '+s;
    vector<vector<int>> cnt(n+1,vector<int>(26,0));// cnt[i][c] is count of character c in s[1,i]
    for(int c=0;c<26;c++){
        for(int i=1;i<=n;i++){
            cnt[i][c]=cnt[i-1][c]+(s[i]==c+'a');
        }
    }
    int q;cin>>q;
    while(q--){
        int l,r;cin>>l>>r;
        bool ok=0;
        if(l==r) ok=1;
        if(s[l]!=s[r]) ok=1;
        
        // check for 3 distinct chars in s[l,r]
        int freq=0;
        for(int c=0;c<26;c++){
            if(cnt[r][c]-cnt[l-1][c]>0) freq++;
        }
        if(freq>=3) ok=1;

        cout<<(ok?"Yes":"No")<<'\n';
    }
    return 0;
}