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
       int n;cin>>n;
       vector<int> a;
       int x;cin>>x;a.push_back(x);
       for(int i=0;i<n-1;i++) {
        // prevent contiguos blocks of same elts
        int x;cin>>x;
        if( x!=*a.rbegin()) a.push_back(x);
       }
       // count no. of local maximas
       n = a.size();
        int ans = 0;
        if (n == 1) {
            ans = 1; // the only element is a peak
        } else {
            if (a[0] > a[1]) ans++;
            for (int i = 1; i < n - 1; i++) {
                if (a[i] > a[i - 1] && a[i] > a[i + 1]) ans++;
            }
            if (a[n - 1] > a[n - 2]) ans++;
        }
       cout<<ans<<"\n";

    }
    return 0;
}