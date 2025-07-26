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
       vector<int> t(n);for(auto &i:t) cin>>i;
       vector<pair<int,int>> pts;
       for(int i=1;i<5*n;i++){
        for(int j=1;j<5*n;j++){
            pts.push_back({i,j});
        }
       }
       auto d=[](pair<int,int> p1,pair<int,int> p2){
        return abs(p1.first)+abs(p2.second);
       };
       sort(all(pts),[](auto p1,auto p2){
        if(d(p1)!=d(p2)){
            return d(p1)<d(p2);
        }
        else if(p1.first!=p2.first){
            return p1.first<p2.first;
        }
        else{
            return p1.second<p2.second;
        }
       });

       auto isT=[](int x,int y){
        return ((x-1)%3==0 && (y-1)%3==0) ||
        ((x-1)%3==0 && (y-2)%3==0) ||
        ((x-2)%3==0 && (y-1)%3==0) || 
        ((x-2)%3==0 && (y-2)%3==0);
       };
       vector<vector<int>> grid(5*n,vector<int>(5*n,0));
       for(auto [x,y]:pts){
        if(isT(x,y)){
            
        }
       }
    }
    return 0;
}