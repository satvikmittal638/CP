#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

int main()
{
    fastio;
    ll a, b;
    char c; 
    vector<pair<ll,ll>> crds;
    while (cin >> a >> c >> b) {
        crds.emplace_back(a,b);
    }
    crds.push_back(crds[0]); 
    
    vector<ll> i_comp,j_comp;
    i_comp.push_back(-1); j_comp.push_back(-1); // Buffer for 1-based indexing
    
    for(auto &[i,j]:crds){
        i_comp.push_back(i);
        j_comp.push_back(j);
    }
    
    sort(all(i_comp)); i_comp.erase(unique(all(i_comp)),i_comp.end());
    sort(all(j_comp)); j_comp.erase(unique(all(j_comp)),j_comp.end());
    
    map<ll,ll> invi,invj;
    for(int i=1;i<i_comp.size();i++) invi[i_comp[i]]=i;
    for(int i=1;i<j_comp.size();i++) invj[j_comp[i]]=i;
    
    int H = i_comp.size(); 
    int W = j_comp.size();
    
    // 0->empty, 1->tile, 2->visited_outside
    vector<vector<int>> grid(H+2, vector<int>(W+2, 0));

    // Draw Boundaries
    for(int i=0;i<crds.size()-1;i++){
        auto [i1,j1]=crds[i];
        i1=invi[i1]; j1=invj[j1];
        auto [i2,j2]=crds[i+1];
        i2=invi[i2]; j2=invj[j2];

        if(j1==j2){
            if(i1>i2) swap(i1,i2);
            for(int k=i1;k<=i2;k++) grid[k][j1]=1;
        }
        else{
            if(j1>j2) swap(j1,j2);
            for(int k=j1;k<=j2;k++) grid[i1][k]=1;
        }
    }

    // Flood Fill (BFS) to mark outside area
    // Start from (0,0) which corresponds to the -1 buffer
    queue<pair<int,int>> q;
    q.push({0,0});
    grid[0][0] = 2; // 2 represents "Outside"

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    while(!q.empty()){
        auto [r, c] = q.front();
        q.pop();

        for(int k=0; k<4; k++){
            int nr = r + dx[k];
            int nc = c + dy[k];

            // Check bounds (0 to H and 0 to W covers the whole padded grid)
            if(nr >= 0 && nr <= H && nc >= 0 && nc <= W){
                if(grid[nr][nc] == 0){ // If empty and not visited
                    grid[nr][nc] = 2;
                    q.push({nr, nc});
                }
            }
        }
    }

    // Convert Grid: Anything not "2" is Inside (1)
    for(int i=1; i<H; i++){
        for(int j=1; j<W; j++){
            if(grid[i][j] != 2) grid[i][j] = 1; // It is boundary or inside
            else grid[i][j] = 0; // It is outside, set back to 0 for prefix sum
        }
    }

    // Prefix Sums
    vector<vector<ll>> p(H+1, vector<ll>(W+1, 0));
    for(int i=1; i<H; i++){
        for(int j=1; j<W; j++){
            p[i][j] = (p[i-1][j] + p[i][j-1] - p[i-1][j-1]) + grid[i][j];
        }
    }

    crds.pop_back(); 
    ll ans = 0;

    // Check All Pairs
    for(int i=0; i<crds.size(); i++){
        for(int j=i+1; j<crds.size(); j++){
            auto p1 = crds[i];
            auto p2 = crds[j];
            
            // Original coordinates for final calculation
            ll r1_orig = p1.first, c1_orig = p1.second;
            ll r2_orig = p2.first, c2_orig = p2.second;

            // Compressed coordinates for grid check
            int i1 = invi[r1_orig];
            int j1 = invj[c1_orig];
            int i2 = invi[r2_orig];
            int j2 = invj[c2_orig];

            // Ensure i1 <= i2, j1 <= j2 for prefix sum math
            int r_min = min(i1, i2);
            int r_max = max(i1, i2);
            int c_min = min(j1, j2);
            int c_max = max(j1, j2);

            ll ar = p[r_max][c_max] - p[r_min-1][c_max] - p[r_max][c_min-1] + p[r_min-1][c_min-1];
            ll ar2 = (ll)(abs(i1-i2)+1) * (ll)(abs(j1-j2)+1); // Points in compressed grid

            if(ar == ar2){
                // Valid rectangle, calculate REAL area
                ll area = (abs(r1_orig - r2_orig) + 1) * (abs(c1_orig - c2_orig) + 1);
                ans = max(ans, area);
            }
        }
    }
    cout << ans;
    return 0;
}