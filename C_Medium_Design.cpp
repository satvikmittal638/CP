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
       vector<pair<int,int>> itvlNo1,itvlNom;// minm at 1 or m is always achievable in a optimal soln
       while(n--){
        int l,r;cin>>l>>r;
        if(l>1){
            itvlNo1.emplace_back(l,1);
            itvlNo1.emplace_back(r+1,-1);
        }
        if(r<m){
            itvlNom.emplace_back(l,1);
            itvlNom.emplace_back(r+1,-1);
        }
        // in case of l[i]=r[j](i!=j) we will want to consider index i(or j) as covered, hence we close a bit later, at r+1 to achieve that
       }
       sort(all(itvlNo1));
       sort(all(itvlNom));

       auto maxRooms=[](vector<pair<int,int>> itvl){
        int cur=0,ans=0;
        for(const auto &[l,val]:itvl){
            cur+=val;
            ans=max(ans,cur);
        }
        return ans;
       };
       cout<<max(maxRooms(itvlNo1),maxRooms(itvlNom))<<'\n';// a min of 0 is always achievable
       

    }
    return 0;
}