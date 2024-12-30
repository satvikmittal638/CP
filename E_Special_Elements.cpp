#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

bool hasTargetSum(const vector<int>& arr, int target) {
    int current_sum = 0;
    int start = 0;

    for (int end = 0; end < arr.size(); ++end) {
        current_sum += arr[end];

        while (current_sum > target && start <= end) {
            current_sum -= arr[start];
            ++start;
        }

        if (current_sum == target && start!=end) {
            return true;
        }
    }

    return false;
}


int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<int> a(n);for(auto &i:a) cin>>i;
       int ans=0;
        for(int i=0;i<n;i++){
            ans+=hasTargetSum(a,a[i]);
        }
        cout<<ans<<"\n";
    }
    return 0;
}