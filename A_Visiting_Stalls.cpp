#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()

int main() {
    fastio;
    int n, t, x;
    cin >> n >> t >> x;
    
    
    vector<int> vis(x + 1, 0);
    for (int i = 1; i <= x; i++) {
        cin >> vis[i];
        vis[i] %= n; // Convert input to valid stall index
    }

    vector<int> stalls(n, -1), ans(x + 1, -1);

    for (int i = 1; i <= x; i++) {
        int j = vis[i];  
        int start = j; // Track start position to detect full cycle
        int minT=INT_MAX,minInd=-1;
        while (stalls[j] != -1 && i<stalls[j]) {
            if(i<minT){
                minT=i;
                minInd=j;
            }
            j = (j + 1) % n;
            if (j == start) { // If we return to start, all stalls are full
                j=-1;
                break;
            }
        }
            int myT=i;
            if(j==-1){
                j=minInd;
                myT=minT;
            }
            stalls[j] = myT; // timestamp the time of assignment 
            ans[i] = j;// assign the stall
    }

    for (int i = 1; i <= x; i++) 
        cout << ans[i] << "\n";
    
    return 0;
}