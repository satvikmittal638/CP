#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n,m,h;cin>>n>>m>>h;
       vector<pair<int,pair<long long,long long>>> ldb;
       for(int i=0;i<n;i++){
        vector<int> t(m);for(auto &i:t) cin>>i;
        sort(t.begin(),t.end());
        long long score=0,penalty=0,time_elapsed=0;
        for(int j=0;j<m;j++){
            time_elapsed+=t[j];
            if(time_elapsed<=h){
                score++;
                penalty+=time_elapsed;
            }else{
                break;
            }
        }
        ldb.emplace_back(make_pair(i,make_pair(score,penalty)));
       }
        sort(ldb.begin(),ldb.end(),[](pair<int,pair<long long,long long>>p1,pair<int,pair<long long,long long>> p2){
            if(p1.second.first!=p2.second.first)
                return p1.second.first>p2.second.first;
            
            if(p1.second.second!=p2.second.second)
                return p1.second.second<p2.second.second;
            return p1.first<p2.first;
        });
        int rank=0;
        for(auto p:ldb){
            rank++;
            if(p.first==0){
                break;
            }
        }
        cout<<rank<<"\n";
    }
    return 0;
}