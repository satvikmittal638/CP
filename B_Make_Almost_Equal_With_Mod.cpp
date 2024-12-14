#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<long long>& a,long long M){
    map<long long,long long> mp;
    for(auto e:a){
        mp[e%M]++;
    }
    return mp.size()==2;
}

int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
        vector<long long> a(n);for(auto &i:a) cin>>i;
        long long k=2;
        while(!isSafe(a,k)){
            k*=2;
        }
        cout<<k<<"\n";
    }
    return 0;
}