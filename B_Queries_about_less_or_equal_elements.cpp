#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
  
    int n,m;cin>>n>>m;
    vector<int> a(n);
    for(auto &i:a) cin>>i;
    sort(all(a));
    for(int i=0;i<m;i++){
        int b;cin>>b;
        auto it=upper_bound(all(a),b);
        it--;
        cout<<it-a.begin()+1<<" ";
    }
    return 0;
}