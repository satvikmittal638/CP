#include<bits/stdc++.h>
using namespace std;
int main()
{
    const int MAX=1000;
    int tt;cin>>tt;
    while(tt--){
       int n,q;cin>>n>>q;
       vector<vector<long long>> a(MAX+1,vector<long long>(MAX+1,0));
       vector<vector<long long>> pref(MAX+1,vector<long long>(MAX+1,0));
        while(n--){
            long long h,w;cin>>h>>w;
            a[h][w]+=h*w;
        }

        for(int i=1;i<=MAX;i++){
            for(int j=1;j<=MAX;j++){
                pref[i][j] = pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1]+a[i][j];
            }
        }

        while(q--){
            long long hs,ws,hb,wb;cin>>hs>>ws>>hb>>wb;
            long long sum=pref[hb-1][wb-1]
                            -pref[hb-1][ws]
                            -pref[hs][wb-1]
                            +pref[hs][ws];
            cout<<sum<<"\n";
        }
    }
    return 0;
}