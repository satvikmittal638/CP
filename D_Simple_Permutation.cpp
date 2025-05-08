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
        int n;
        cin >> n;
        vector<int> p(n+1);
        iota(p.begin()+1, p.end(), 1);
        swap(p[1],p[2]);

        for (int i=1;i<=n;i++) {
            cout << p[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}