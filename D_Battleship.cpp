#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int n;cin>>n;
    vector<vector<int>> grid(11,vector<int>(11,0));
    bool ok=1;
    while(n--){
        int d,l,r,c;cin>>d>>l>>r>>c;
        if(d==0){
            ok&=(c+l-1<=10);
            if(ok){
                for(int j=c;j<=c+l-1;j++) grid[r][j]++;
            }
        }
        else{
            ok&=(r+l-1<=10);
            if(ok){
                for(int i=r;i<=r+l-1;i++) grid[i][c]++;
            }
        }
    }
    for(int i=1;i<=10;i++){
        for(int j=1;j<=10;j++){
            ok&=(grid[i][j]<=1);
        }
    }
    cout<<(ok?"Y":"N")<<'\n';
    return 0;
}