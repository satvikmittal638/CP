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
        int nm=n*m;
       vector<vector<int>> a(n,vector<int>(m)),b(n,vector<int>(m));
       // maintain row and col of each element before and after row/col swaps
        vector<int> pos1i(nm),pos2i(nm),pos1j(nm),pos2j(nm);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
                a[i][j]--;
                pos1i[a[i][j]]=i;
                pos1j[a[i][j]]=j;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>b[i][j];
                b[i][j]--;
                pos2i[b[i][j]]=i;
                pos2j[b[i][j]]=j;
            }
        }

        // check if those elements which were in the same row earlier are still in the same row
        // check if those elements which were in the same col earlier are still in the same col
        vector<set<int>> pi(nm),pj(nm);
        for(int x=0;x<nm;x++){
            int i1=pos1i[x],j1=pos1j[x],
                i2=pos2i[x],j2=pos2j[x];
            pi[i1].insert(i2);
            pj[j1].insert(j2);
        }
        bool ok=1;
        for(int x=0;x<nm;x++){
            if(pi[x].size()>1 || pj[x].size()>1){
                ok=0;
                break;
            }
        }
        cout<<(ok?"YES":"NO")<<"\n";

    }
    return 0;
}