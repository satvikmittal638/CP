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
    int r=0;
    vector<int> fin(3,-1);
    fin[0]=0;
    /*
    z[i] is ans for a prefix of length i
    */
    vector<int> z(n+1);
    for(int i=1;i<=n;i++){
        r=(r+(s[i-1]-'0'))%3;
        z[i]=z[i-1];
        if(fin[r]!=-1){
            z[i]=max(z[i],z[fin[r]]+1);
        }
        fin[r]=i;
    }
    cout<<z[n];
    return 0;
}