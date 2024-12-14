#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,k,x;cin>>n>>k>>x;
    vector<long long> a(n);for(auto &i:a) cin>>i;
    sort(a.begin(),a.end());
    long long cnt=1;
    vector<long long> ds;
    for(long long i=0;i<n-1;i++){
        long long diff=a[i+1]-a[i];
        if(diff>x){
            ds.emplace_back(diff);
            cnt++;
        }
    }
    sort(ds.begin(),ds.end());
    for(auto d:ds){
        /*
        we need ceil(d/x)-1 additional students to cover a gap of d
        */
        long long diff=k-((d+x-1)/x - 1);
        if(diff>=0){
            cnt--;
            k=diff;
        }
    }
    cout<<cnt;
    return 0;
}