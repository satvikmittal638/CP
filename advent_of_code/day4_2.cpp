#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    vector<string> a;
    string s;
    while (cin >> s) a.push_back(s);
    ll ans=0ll;
    for(int z=1;z<=100;z++){
        for(int i=0;i<a.size();i++){
            for(int j=0;j<a[i].size();j++){
                if(a[i][j]=='.') continue;
                int cnt=0;
                for(int i1=max(0,i-1);i1<=min(i+1,(int)a.size());i1++){
                    for(int j1=max(0,j-1);j1<=min(j+1,(int)a[i].size());j1++){
                        if(i1==i && j1==j) continue;
                        cnt+=a[i1][j1]=='@';
                    }
                }
                if(cnt<4){
                    ans++;
                    a[i][j]='.';
                }
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}