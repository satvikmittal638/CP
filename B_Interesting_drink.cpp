#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    vector<int> x(n);
    for(auto &i:x) cin>>i;
    int q;cin>>q;
    vector<long long> m(q);
    for(auto &i:m) cin>>i;
    sort(x.begin(),x.end());
    for(auto coin:m){
        auto it=upper_bound(x.begin(),x.end(),coin); // smallest element greater than target coin
        cout<<it-x.begin()<<"\n"; // it-1 is the smallest element <= target coin, so i take advantage of 0 based indexing here
    }
    return 0;
}