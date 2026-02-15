#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) x.begin(),x.end()

int main()
{
    fastio;
    int n, q;
    cin >> n >> q;

    vector<int> a(n+1);
    for(int i=1; i<=n; i++) cin >> a[i];

    vector<int> pxor(n+1, 0), cnt0(n+1, 0);
    
    // Store pairs {value, index} in two large vectors
    // indices[0] for even positions, indices[1] for odd positions
    vector<pair<int, int>> indices[2]; 

    for(int i=1; i<=n; i++){
        pxor[i] = pxor[i-1] ^ a[i];
        cnt0[i] = cnt0[i-1] + (a[i] == 0);
        
        // Push to flat vector (Very fast)
        indices[i%2].push_back({pxor[i], i});
    } 

    // Sort the flat vectors (N log N)
    // This groups identical XOR values together, ordered by index
    sort(all(indices[0]));
    sort(all(indices[1]));

    while(q--){
        int l, r;
        cin >> l >> r;
        int target = pxor[l-1];

        if((pxor[r] ^ target) == 0){
            // Case: All zeros
            if(cnt0[r] - cnt0[l-1] == r - l + 1){
                cout << "0\n";
                continue;
            }
            // Case: Odd Length
            if((r - l + 1) % 2 != 0){
                cout << "1\n";
                continue;
            }
            // Case: Boundary Zeros
            if(a[l] == 0 || a[r] == 0){
                cout << "1\n";
                continue;
            }

            // Case: Even Length -> Split
            // Binary search in the flat vector
            const auto &vec = indices[l%2];
            
            // Search for first pair where {val, idx} >= {target, l}
            auto it = lower_bound(all(vec), make_pair(target, l));
            
            // Check if we found a valid match strictly inside [l, r)
            if(it != vec.end() && it->first == target && it->second < r){
                cout << "2\n";
            } else {
                cout << "-1\n";
            }
        }
        else{
            cout << "-1\n";
        }
    }
    return 0;
}