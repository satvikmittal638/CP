#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n,m,v;cin>>n>>m>>v;
       vector<long long> a(n);for(auto &i:a) cin>>i;
       vector<long long> pref,suf;
       /*
       **i is 1-indexed
       pref[i] denotes the sum of tastiness of first i pieces (>=v) from start
       suf[i] denotes the sum of tastiness of first i pieces (>=v) from end
       */
      pref.emplace_back(0);suf.emplace_back(0); // base case 


      // build prefix
      for(long long i=0, piece=0;i<n;i++){
        piece+=a[i];
        //greedily cut the piece        
        if(piece>=v){
            pref.emplace_back(piece+*(pref.end()-1));
            piece=0;//reset for another piece
        }
      }

      // build suffix
      for(long long i=n-1, piece=0;i>=0;i--){
        piece+=a[i];
        //greedily cut the piece
        if(piece>=v){
            suf.emplace_back(piece+*(suf.end()-1));
            piece=0;//reset for another piece
        }
      }
      // m+1 to consider the '0' initialisation
      if(pref.size()>=m+1){
        /*
        take i pieces from start and m-i from end. 
        remaining middle part goes to alice
        */ 
        long long maxAns=LLONG_MIN,total=accumulate(a.begin(),a.end(),0LL);
        for(int i=0;i<=m;i++){
            maxAns=max(maxAns,total-(pref[i]+suf[m-i]));
        }
        cout<<maxAns<<"\n";
      }else{
        cout<<"-1\n";
      }

      

    }
    return 0;
}