#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()

int main() {
    fastio;
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (auto &i : a) cin >> i;
        for (auto &i : b) cin >> i;
        vector<pair<int,int>> cust(n);
        for(int i=0;i<n;i++){
            cust[i]={a[i],b[i]};
        }
        sort(rall(cust)) ; // first in descending by a[i],then by b[i]
        sort(all(a));
        sort(all(b));
        ll maxCost=0ll;
        for(int i=0;i<n;i++){
            int lo=cust[i].first,hi=cust[i].second;
            while(lo<hi){
                int mid=(lo+hi+1)/2;
                int cnt_neg=lower_bound(a.begin()+n-i,a.end(),mid)-a.begin();
                if(cnt_neg<=k){
                    lo=mid;
                }else{
                    hi=mid-1;
                }
            }
            ll curCost=(ll)lo*(i+1);
            maxCost=max(maxCost,curCost);
        }
        cout<<maxCost<<"\n";    
    }
    return 0;
}