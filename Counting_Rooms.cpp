#include<bits/stdc++.h>
using namespace std;
vector<vector<char>> grid;
vector<vector<bool>> visited;
int n,m;

// bool isValid(vector<int> coord){
//     if(
//         0<=coord[0] && coord[0]<n &&
//         0<=coord[1] && coord[1]<m &&
//         grid[coord[0]][coord[1]]=='.'
//     ) return 1;
//     return 0;
// }

// vector<vector<int>> ngbrs(int i, int j) {
//     vector<vector<int>> potential_ngbrs = {
//         {i-1, j}, {i, j-1}, {i+1, j}, {i, j+1}
//     };
//     vector<vector<int>> valid_ngbrs;
//     for (auto& coord : potential_ngbrs) {
//         if (isValid(coord)) {
//             valid_ngbrs.push_back(coord);
//         }
//     }
//     return valid_ngbrs;
// }


// check neighbours inline to reduce time OW get TLE
// Direction vectors for DFS: top, left, bottom, right
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void dfs(int x, int y) {
    visited[x][y] = true;

    // Check all 4 neighbors
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];

        // Only proceed if the neighbor is within bounds, unvisited, and is a '.'
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && 
            grid[nx][ny] == '.' && !visited[nx][ny]) {
            dfs(nx, ny);  // Recursive call
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;
    grid.assign(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    visited.assign(n,vector<bool>(m,0));

    int cnt_rooms=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='.' && !visited[i][j]){
                cnt_rooms++;
                dfs(i,j);
            }
        }
    }
    cout<<cnt_rooms;

    return 0;
}