#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    vector<string> grid;
    string line;

    while (getline(cin, line)) {
        grid.push_back(line);
    }
    vector<bool> hasBeam(grid[0].size(),0);
    for(int j=0;j<grid[0].size();j++){
        if(grid[0][j]=='S'){
            hasBeam[j]=1;
            break;
        }
    }
    ll ans=0ll;
    for(int i=1;i<grid.size();i++){
        for(int j=0;j<grid[i].size();j++){
            if(grid[i][j]=='^' && hasBeam[j]){
                ans++;
                // split the beam
                hasBeam[j-1]=1;
                hasBeam[j]=0;
                hasBeam[j+1]=1;
            }
        }
    }
    cout<<ans;
    return 0;
}