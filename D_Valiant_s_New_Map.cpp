#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n,m;cin>>n>>m;
       vector<vector<int>> a(n,vector<int>(m,0));
       for(auto &i:a) for(auto &j:i) cin>>j;
       // check if k works or not
       auto isSafe=[&](int k){
           // perform sliding window minm on each row(window size=k)
        vector<vector<int>> rowMin(n, vector<int>(m - k + 1));
        for(int i = 0; i < n; i++){
            deque<int> dq;
            for(int j = 0; j < m; j++){
                while(!dq.empty() && a[i][dq.back()] >= a[i][j]) dq.pop_back();
                dq.push_back(j);
                if(dq.front() <= j - k) dq.pop_front();
                if(j >= k - 1) rowMin[i][j - k + 1] = a[i][dq.front()];
            }
        }

        bool found=0;
        int cols = m - k + 1;
        for(int j = 0; j < cols; j++){
            deque<int> dq;
            for(int i = 0; i < n; i++){
                while(!dq.empty() && rowMin[dq.back()][j] >= rowMin[i][j]) dq.pop_back();
                dq.push_back(i);
                if(dq.front() <= i - k) dq.pop_front();
                if(i>=k-1 && rowMin[dq.front()][j] >= k){
                    found = 1;
                    break;
                }
            }
            if(found) break;
        }
        return found;
       };
       
       // BS on k
       int lo = 1, hi = min(n,m),ans=1;
       while(lo<=hi){
        int mid=(lo+hi)/2;
        if(isSafe(mid)){
            ans=mid;
            lo=mid+1;
        }
        else{
            hi=mid-1;
        }
       }
       cout<<ans<<'\n';
    }
    return 0;
}