#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

struct state {
    int x, y;
    int dir; // direction: 0=Up, 1=Left, 2=Down, 3=Right
    int streak;
    int steps;
};

int main()
{
fastio;
    int n,m;cin>>n>>m;
    vector<string> a(n);for(auto &i:a) cin>>i;
    vector<pair<int,int>> dirn={{-1,0},{0,-1},{1,0},{0,1}};
    vector<vector<vector<int>>> vis(n, vector<vector<int>>(m, vector<int>(4, -1)));
    queue<state> q;

    int sx,sy;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='S'){
                sx=j;
                sy=i;
                break;
            }
        }
    }
    
    // take a step from the start
    for (int d = 0; d < 4; ++d) {
        int dx = dirn[d].first;
        int dy = dirn[d].second;
        int nx = sx + dx, ny = sy + dy;
        if (0 <= nx && nx < m && 0 <= ny && ny < n && a[ny][nx] != '#') {
            q.push({nx, ny, d, 1, 1});
            vis[ny][nx][d] = 1;
        }
    }

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        if (a[cur.y][cur.x] == 'T') {
            cout << cur.steps << "\n";
            return 0;
        }

        for (int d = 0; d < 4; ++d) {
            int dx = dirn[d].first;
            int dy = dirn[d].second;
            int nx = cur.x + dx, ny = cur.y + dy;
            if (0 <= nx && nx < m && 0 <= ny && ny < n && a[ny][nx] != '#') {
                int new_streak = (d == cur.dir) ? cur.streak + 1 : 1;
                if (new_streak > 3) continue; // falls down, so can't move
                if (vis[ny][nx][d] != -1 && vis[ny][nx][d] <= new_streak) continue; // 
                vis[ny][nx][d] = new_streak;
                q.push({nx, ny, d, new_streak, cur.steps + 1});
            }
        }
    }

    cout << "-1\n";
    return 0;
}