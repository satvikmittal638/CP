#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    string line;

    vector<vector<string>> tiles;

    // ---------- READ TILES ----------
    while (getline(cin, line)) {
        if (line.empty()) continue;

        // queries start when we see 'x'
        if (line.find('x') != string::npos)
            break;

        // parse tile id
        int id = stoi(line.substr(0, line.find(':')));

        // ensure vector is large enough
        if ((int)tiles.size() <= id)
            tiles.resize(id + 1);

        // read grid (3x3 assumed)
        vector<string> grid(3);
        for (int i = 0; i < 3; i++)
            getline(cin, grid[i]);

        tiles[id] = grid;
    }
    // precompute area of each tile
    // vector<ll> ar(tiles.size(),0ll);
    // for(int i=0;i<tiles.size();i++){
    //     for(int j=0;j<3;j++){
    //         for(int k=0;k<3;k++){
    //             ar[i]+=(tiles[i][j][k]=='#');
    //         }
    //     }
    // }
    // function to check if this region can accomodate all of its tiles
    auto solve=[&](int h,int w,vector<int> seq){
        ll mxTiles=(h/3)*(w/3); // maxm 3X3 tiles it can have
        return accumulate(all(seq),0ll)<=mxTiles;
    };
    // ---------- READ QUERIES AND ANSWER----------
    ll ans=0ll;
    do {
        if (line.empty()) continue;

        int h, w;
        sscanf(line.c_str(), "%dx%d:", &h, &w);

        string rest = line.substr(line.find(':') + 1);
        stringstream ss(rest);

        vector<int> seq;
        int x;
        while (ss >> x) seq.push_back(x);

        // solve
        ans+=solve(h,w,seq);
        
    } while (getline(cin, line));
    cout<<ans;

    return 0;
}