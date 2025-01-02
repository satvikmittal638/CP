#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
    fastio;
    int h, w;
    cin >> h >> w;
    vector<string> grid(h + 1);
    for (int i = 1; i <= h; i++) {
        string s;
        cin >> s;
        grid[i] = " " + s; 
    }

    vector<vector<int>> hor(h + 1, vector<int>(w + 1, 0));
    vector<vector<int>> ver(h + 1, vector<int>(w + 1, 0));

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (j < w && grid[i][j] == '.' && grid[i][j + 1] == '.') 
                hor[i][j] = 1;
            if (i < h && grid[i][j] == '.' && grid[i + 1][j] == '.') 
                ver[i][j] = 1;

            hor[i][j] += hor[i - 1][j] + hor[i][j - 1] - hor[i - 1][j - 1];
            ver[i][j] += ver[i - 1][j] + ver[i][j - 1] - ver[i - 1][j - 1];
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        // no. of ways is no. of good cells in (r1,c1) and (r2,c2-1)
        int ansH = hor[r2][c2-1] - hor[r1 - 1][c2-1] - hor[r2][c1 - 1] + hor[r1 - 1][c1 - 1];
        // no. of ways is no. of good cells in (r1,c1) and (r2-1,c2)
        int ansV = ver[r2-1][c2] - ver[r1 - 1][c2] - ver[r2-1][c1 - 1] + ver[r1 - 1][c1 - 1];
        cout << ansH + ansV << "\n";
    }

    return 0;
}