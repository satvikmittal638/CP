#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

int main() {
    fastio;
    int n; cin >> n;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++) cin >> a[i];
    
    vector<vector<int>> dp_lis(n+1, vector<int>(n+1, 0));
    vector<vector<int>> dp_lds(n+1, vector<int>(n+1, 0));
    
    // Compute dp_lis: Longest Non-decreasing ending at r for each [l, r]
    for(int l=1; l<=n; l++) {
        int mx_1 = 0, mx_2 = 0;
        for(int r=l; r<=n; r++) {
            if(a[r] == 1) {
                dp_lis[l][r] = 1 + mx_1;
                mx_1 = max(mx_1, dp_lis[l][r]);
            } else {
                dp_lis[l][r] = 1 + max(mx_1, mx_2);
                mx_2 = max(mx_2, dp_lis[l][r]);
            }
        }
    }
    
    // Compute dp_lds: Longest Non-increasing ending at r for each [l, r]
    for(int l=1; l<=n; l++) {
        int mx_1 = 0, mx_2 = 0;
        for(int r=l; r<=n; r++) {
            if(a[r] == 1) {
                dp_lds[l][r] = 1 + max(mx_1, mx_2);
                mx_1 = max(mx_1, dp_lds[l][r]);
            } else {
                dp_lds[l][r] = 1 + mx_2;
                mx_2 = max(mx_2, dp_lds[l][r]);
            }
        }
    }
    
    // !! Key step I was missing
    // Precompute max_lis and max_lds for all segments [a, b]
    vector<vector<int>> max_lis(n+2, vector<int>(n+2, 0));
    vector<vector<int>> max_lds(n+2, vector<int>(n+2, 0));
    
    for(int a=1; a<=n; a++) {
        int current_max_lis = 0;
        int current_max_lds = 0;
        for(int b=a; b<=n; b++) {
            current_max_lis = max(current_max_lis, dp_lis[a][b]);
            max_lis[a][b] = current_max_lis;
            current_max_lds = max(current_max_lds, dp_lds[a][b]);
            max_lds[a][b] = current_max_lds;
        }
    }
    
    int ans = max_lis[1][n]; // Without any reversal
    
    for(int l=1; l<=n; l++) {
        for(int r=l; r<=n; r++) {
            int left = (l > 1) ? max_lis[1][l-1] : 0;
            int mid = max_lds[l][r];
            int right = (r < n) ? max_lis[r+1][n] : 0;
            ans = max(ans, left + mid + right);
        }
    }
    
    cout << ans;
    return 0;
}