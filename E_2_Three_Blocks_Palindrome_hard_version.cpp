#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
const int A=200;
#ifndef ONLINE_JUDGE
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
#else
#define error(args...)
#endif
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<int> a(n);
       vector<vector<int>> pos(A+1);
       for(int i=0;i<n;i++){
        cin>>a[i];
        pos[a[i]].emplace_back(i);
       }
       vector<vector<int>> p(A+1,vector<int>(n,0));
       for(int i=1;i<=A;i++){
        for(int j=0;j<n;j++){
            if(j>0)p[i][j]=p[i][j-1];
            p[i][j]+=a[j]==i;
        }
       }
       int ans=1;// single elt always an ans
       // top 2 loops combine together to give a O(n)
       // inside maxm finding loop works in O(A)
       // so total O(nA)
       for(int z=1;z<=A;z++){
        // go only till half to keep l<=r
           for(int j=0;j<pos[z].size()/2;j++){
                int cnt_pref=j+1,mx=0;
                int l=pos[z][j],r=pos[z][pos[z].size()-cnt_pref];
                // now we aim to get maxm freq of any elt on [l+1,r-1]
                // get max(p[i][r-1]-p[i][l]) over all 1<=i<=A
                for(int i=1;i<=A;i++){
                    mx=max(mx,p[i][r-1]-p[i][l]);
                }
                ans=max(ans,mx+2*cnt_pref);
           }
       }
       cout<<ans<<'\n';
    }
    return 0;
}